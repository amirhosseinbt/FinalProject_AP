#include "settingw.h"
#include "ui_settingw.h"

SettingW::SettingW(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingW)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
    this->setStyleSheet("QLineEdit{border-radius:10px;border:1px solid #2D25A4;background-color:#E1DBED;}"
                        "QTextEdit,QDateEdit{border-radius:10px;background: palette(base);border:1px solid #2D25A4;background-color:#E1DBED;}");
    ui->btn_change->setStyleSheet("QPushButton{border:2px solid #2D25A4;border-radius:20px;padding:10px;}");
    ui->btn_changepic->setStyleSheet("QPushButton{border:none;}");
    ui->btn_delaccount->setStyleSheet("QPushButton{border:2px solid #2D25A4;border-radius:20px;padding:10px;}");
    ui->btn_headerchange->setStyleSheet("QPushButton{border:none;}");

    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString("#FFFFFF"));

    QPixmap Color(":/icons/img/color.png");
    QIcon Color_icnon(Color);
    ui->btn_headerchange->setIcon(Color_icnon);
    ui->btn_headerchange->setIconSize(QSize(80,80));
    ui->btn_headerchange->setFixedSize(QSize(80,80));


    QPixmap Upload(":/icons/img/upload.png");
    QIcon Upload_icnon(Upload);
    ui->btn_changepic->setIcon(Upload_icnon);
    ui->btn_changepic->setIconSize(QSize(80,80));
    ui->btn_changepic->setFixedSize(QSize(80,80));

}

void SettingW::Get_User(User *user)// fill the account information for changing
{
    Current_User = user;
    connect(Current_User,SIGNAL(Validate(QString&,QValidator::State&)),this,SLOT(Validator(QString&,QValidator::State&)));
    picture_path = Current_User->Get_Picture_Path();
    Selected_Color = QColor::fromString(Current_User->Get_Header());
    QPixmap profile_picture(Current_User->Get_Picture_Path());

    ui->widget->setAutoFillBackground(true);
    ui->widget->setPalette(QColor::fromString(Current_User->Get_Header()));

    ui->lbl_profpic->setFixedSize(100,100);
    ui->lbl_profpic->setPixmap(profile_picture.scaled(ui->lbl_profpic->width(),ui->lbl_profpic->height(),Qt::KeepAspectRatio));

    ui->txt_username->setText(Current_User->Get_Username());

    ui->txt_name->setText(Current_User->Get_Name());

    ui->txt_country->setText(Current_User->Get_Country());

    ui->txt_phonenumber->setText(Current_User->Get_Phonenumber());

    ui->txt_link->setText(Current_User->Get_Link());

    ui->txt_biography->setText(Current_User->Get_Biography());

    // customizing window for each account

    if(Current_User->Get_Type()=="O")
    {
        ui->txt_orgusername->setReadOnly(true);
        ui->brthdate->setReadOnly(true);
        ui->brthdate->setHidden(true);
        ui->lbl_brthdate->setHidden(true);
        ui->txt_adminusername->setText(dynamic_cast<Organization_User*>(Current_User)->Get_Admin_Username());
    }

    else if(Current_User->Get_Type()=="P")
    {
        ui->txt_adminusername->setReadOnly(true);
        ui->txt_orgusername->setText(dynamic_cast<Personal_User*>(Current_User)->Get_Organ_Uname());
        ui->brthdate->setDate(dynamic_cast<Personal_User*>(Current_User)->Get_Birthday());

    }
    else
    {
        ui->txt_orgusername->setReadOnly(true);
        ui->txt_adminusername->setReadOnly(true);
        ui->txt_name->setReadOnly(true);
    }


}

void SettingW::Selected_color(QColor color)
{
    Selected_Color = color;
}

void SettingW::Picture_Path(QString path)
{
    picture_path = path;
}

SettingW::~SettingW()
{
    delete ui;
    delete Current_User;
}

void SettingW::Validator(QString &message, QValidator::State &st)
{
    if(st == QValidator::Invalid)
    {
        QMessageBox::information(this,"Warning",message);
        return;
    }
}

void SettingW::on_btn_change_clicked() // returns are for avoiding show many message at the same time
{
    if(ui->txt_username->text() != Current_User->Get_Username() && !ui->txt_username->text().isEmpty())
    {
        QFile Users ("User_file.txt");
        if(!Users.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            QMessageBox::information(this,"Warning","! File can not open.");
            return;
        }
        else
        {
            QTextStream file(&Users);
            QStringList user_list;
            bool flag_check_username = false;
            while(!file.atEnd())
            {
                user_list = file.readLine().split("%$%");
                if(ui->txt_username->text() == user_list.at(1))
                {
                    flag_check_username =true;
                    QMessageBox::information(this,"Warning","! Username exists");
                    break;
                }
            }
            if(!flag_check_username)
            {
                if(!Current_User->Set_Username(ui->txt_username->text()))
                {
                    return;
                }
            }
            Users.close();
        }
    }
    else if(ui->txt_username->text().isEmpty())
    {
        QMessageBox::information(this,"Warning","! You must enter Username.");
        return;

    }
    if(ui->txt_password->text().isEmpty())
    {
        QMessageBox::information(this,"Warning","! You must enter Password.");
        return;

    }
    else
    {
        SHA256 secret;
        if(QString::fromStdString( secret(ui->txt_password->text().toStdString()))  != Current_User->Get_Password())
        {

            if(!Current_User->Check_Password_History(ui->txt_password->text())) // check password history
            {
                QMessageBox::information(this,"Warning","! You can not choose your last passwords.");
                return;
            }
            else
            {

                if(!Current_User->Set_Password(ui->txt_password->text()))
                {

                    return; // for ending method
                }
                else
                {
                    Current_User->Set_Password_History(Current_User->Get_Password());
                }
            }
        }
    }
    Current_User->Set_Country(ui->txt_country->text());

    Current_User->Set_Link(ui->txt_link->text());

    Current_User->Set_Birthday(ui->brthdate->date());

    Current_User->Set_Header(Selected_Color.name());

    Current_User->Set_Picture_Path(picture_path);

    QString filter=""; // for deleting \n from text
    for(int i = 0; i <ui->txt_biography->toPlainText().size();i++ )
    {
        if(ui->txt_biography->toPlainText()[i] != '\n')
        {
            filter.append(ui->txt_biography->toPlainText()[i]);
        }
    }
    if(Current_User->Get_Type()=="O")
    {
        if(ui->txt_name->text().isEmpty())
        {
            QMessageBox::information(this,"Warning","! You must enter Name.");
            return;
        }
        else
        {
            Current_User->Set_Name(ui->txt_name->text());

        }
        if(ui->txt_phonenumber->text().isEmpty())
        {
            QMessageBox::information(this,"Warning","! You must enter Phonenumber.");
            return;
        }
        else
        {
            if(!Current_User->Set_Phonenumber(ui->txt_phonenumber->text()))
            {
                return;
            }

        }
        if(ui->txt_adminusername->text().isEmpty())
        {
            QMessageBox::information(this,"Warning","! You must enter AdminUsername.");
            return;
        }
        else
        {
            QFile Users ("User_file.txt");
            if(!Users.open(QIODevice::ReadWrite|QIODevice::Text))
            {
                QMessageBox::information(this,"Warning","! File can not open.");
                return;
            }
            else
            {
                QTextStream file(&Users);
                QStringList user_list;
                bool flag = false;
                while(!file.atEnd())
                {
                    user_list = file.readLine().split("%$%");
                    if(ui->txt_adminusername->text() == user_list.at(1) && user_list.at(0)!="O")
                    {
                        flag =true;
                        dynamic_cast<Organization_User*>(Current_User)->Set_Admin_id(user_list.at(15).toInt());
                    }
                }
                if(!flag)
                {
                    QMessageBox::information(this,"Warning","! Adminusername does not exist.");
                    return;
                }
                Users.close();
            }
        }
        if(!Current_User->Set_Biography(filter))
        {
            return;
        }
        QFile Users ("User_file.txt"); // write changes in file
        if(!Users.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            QMessageBox::information(0,"Warning","! File can not open.");
            return;
        }
        else
        {
            QString str="";
            QTextStream file(&Users);
            while(!file.atEnd())
            {
                QString line = file.readLine();
                QStringList list = line.split("%$%");
                if(list.at(15).toInt() != Current_User->Get_Userid())
                {
                    str.append(line+'\n');
                }
            }
            Users.resize(0);
            file << str;
            file << Current_User;
            Users.close();
        }
        QMessageBox::information(this,"Successful","* Changes saved.");
        emit Send_Current_User(Current_User); // send changed user to mainwindow
        this->close();
    }
    else if(Current_User->Get_Type()=="P")
    {
        if(ui->txt_name->text().isEmpty())
        {
            QMessageBox::information(this,"Warning","! You must enter Name.");
            return;
        }
        else
        {
            Current_User->Set_Name(ui->txt_name->text());
        }
        if(ui->txt_phonenumber->text().isEmpty())
        {
            QMessageBox::information(this,"Warning","! You must enter Phonenumber.");
            return;
        }
        else
        {
            if(!Current_User->Set_Phonenumber(ui->txt_phonenumber->text()))
            {
                return;
            }

        }
        if(!ui->txt_orgusername->text().isEmpty())
        {
            QFile Users ("User_file.txt");
            if(!Users.open(QIODevice::ReadWrite|QIODevice::Text))
            {
                QMessageBox::information(this,"Warning","! File can not open.");
                return;
            }
            else
            {
                QTextStream file(&Users);
                QStringList user_list;
                bool flag = false;
                while(!file.atEnd())
                {
                    user_list = file.readLine().split("%$%");
                    if(ui->txt_orgusername->text() == user_list.at(1) && user_list.at(0)=="O")
                    {
                        flag =true;
                        dynamic_cast<Personal_User*>(Current_User)->Set_Organ_id(user_list.at(15).toInt());
                    }
                }
                if(flag)
                {

                }
                else
                {
                    QMessageBox::information(this,"Warning","! Organusername does not exist.");
                    return;
                }
                Users.close();
            }
            if(!Current_User->Set_Biography(filter))
            {
                return;
            }
        }
        QFile Users ("User_file.txt");
        if(!Users.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            QMessageBox::information(0,"Warning","! File can not open.");
            return;
        }
        else
        {
            QString str="";
            QTextStream file(&Users);
            while(!file.atEnd())
            {
                QString line = file.readLine();
                QStringList list = line.split("%$%");
                if(list.at(15).toInt() != Current_User->Get_Userid())
                {
                    str.append(line+'\n');
                }
            }
            Users.resize(0);
            file << str;
            file << Current_User;
            Users.close();
        }
        QMessageBox::information(this,"Successful","* Changes saved.");
        emit Send_Current_User(Current_User);
        this->close();
    }
    else
    {
        Current_User->Set_Name(ui->txt_name->text());
        if(!Current_User->Set_Phonenumber(ui->txt_phonenumber->text()))
        {
                return;
        }
        if(!Current_User->Set_Biography(filter))
        {
                return;
        }
        QFile Users ("User_file.txt");
        if(!Users.open(QIODevice::ReadWrite|QIODevice::Text))
        {
                QMessageBox::information(0,"Warning","! File can not open.");
                return;
        }
        else
        {
                QString str="";
                QTextStream file(&Users);
                while(!file.atEnd())
                {
                QString line = file.readLine();
                QStringList list = line.split("%$%");
                if(list.at(14).toInt() != Current_User->Get_Userid())
                {
                    str.append(line+'\n');
                }
                }
                Users.resize(0);
                file << str;
                file << Current_User;
                Users.close();
        }
        QMessageBox::information(this,"Successful","* Changes saved.");
        emit Send_Current_User(Current_User);
        this->close();
    }
}


void SettingW::on_btn_headerchange_clicked()
{
    QColor color = QColorDialog::getColor(); // shows a dialog color for selecting header color
    if(color.isValid() && color != QColor::fromString("#ffffff"))
    {
        Selected_color(color);
        ui->widget->setAutoFillBackground(true);
        ui->widget->setPalette(QPalette(color));
    }
}


void SettingW::on_btn_changepic_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,"choose picture",QDir::homePath()); // shows a file dialog for choosing
    // picture
    //if an anonymous user changes picture profile nothing happens
    QByteArray format = QImageReader::imageFormat(file);
    if(format.isEmpty())
    {
        if(!file.isEmpty())//check the format of choosed file
        {
                QMessageBox::information(this,"Warning","! You must choose a picture.");
                return;
        }
    }
    else
    {
        Picture_Path(file);
        QPixmap profile_picture(file);
        ui->lbl_profpic->setFixedSize(150,150);
        ui->lbl_profpic->setPixmap(profile_picture.scaled(ui->lbl_profpic->width(),ui->lbl_profpic->height(),Qt::KeepAspectRatio));
    }
}


void SettingW::on_btn_delaccount_clicked()// Delete all things about account such as like , follow , tweet , password , ... history
{
    QMessageBox MyBox; // make a question box for deleting account
    MyBox.setWindowTitle("Warning");
    MyBox.setText("? Are you sure about deleting account.");
    MyBox.setStandardButtons(QMessageBox::Yes);
    MyBox.addButton(QMessageBox::No);
    MyBox.setDefaultButton(QMessageBox::No);
    if(MyBox.exec() == QMessageBox::Yes)
    {

        QFile Tweets("Tweet_file.txt");
        if(!Tweets.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            QMessageBox::information(0,"Warning","! File can not open.");
            return;
        }
        else
        {
            QString str="";
            QTextStream file(&Tweets);
            while(!file.atEnd())
            {
                QString line = file.readLine();
                QStringList list = line.split("%$%");
                if(list.at(0).toInt() != Current_User->Get_Userid())
                {
                    str.append(line+'\n');
                }
            }
            Tweets.resize(0);
            file << str;
            Tweets.close();
        }
        QFile MentionFF ("Mention_file.txt");
        if(!MentionFF.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            QMessageBox::information(this,"Warning","! File can not open.");
            return;
        }
        else
        {
            QTextStream file(&MentionFF );
            QString str="";
            while(!file.atEnd())
            {
                QString line = file.readLine();
                QStringList list = line.split("%$%");
                if(list.at(6).toInt() == Current_User->Get_Userid()||list.at(0).toInt() == Current_User->Get_Userid())
                {
                }
                else
                {
                    str.append(line+'\n');
                }
            }
            MentionFF.resize(0);
            file << str;
            MentionFF.close();
        }
        QFile History("PassHistory.txt");
        if(!History.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            QMessageBox::information(0,"Warning","! File can not open.");
            return;
        }
        else
        {
            QTextStream file(&History);
            QString str="";
            while(!file.atEnd())
            {
                QString line = file.readLine();
                QStringList list =line.split("%$%");
                if(list.at(0).toInt() != Current_User->Get_Userid())
                {
                    str.append(line+'\n');
                }
            }
            History.resize(0);
            file << str;
            History.close();

        }
        bool Checkflag=true;
        while(Checkflag) // erasing like history
        {
            bool flag = false;
            if(!Tweets.open(QIODevice::ReadWrite|QIODevice::Text))
            {
                QMessageBox::information(this,"Warning","! File can not open.");
                return;
            }
            else
            {
                Tweet* t = new Tweet;
                QTextStream file(&Tweets);
                QStringList list;
                while(!file.atEnd())
                {
                    list = file.readLine().split("%$%");
                    for(int i = 0;i < list.at(4).split(",").size();i++)
                    {
                        if((list.at(4).split(",")).at(i).toInt() == Current_User->Get_Userid())
                        {
                            flag = true;
                            list >> t;
                            t->Erase_Who_Like(Current_User->Get_Userid());
                            break;
                        }
                    }
                    if(flag)
                    {

                        QFile Tfile ("Tweet_file.txt");
                        if(!Tfile.open(QIODevice::ReadWrite|QIODevice::Text))
                        {
                            QMessageBox::information(this,"Warning","! File can not open.");
                            return;
                        }
                        else
                        {
                            QTextStream file(&Tfile);
                            QString str="";
                            while(!file.atEnd())
                            {
                                QString line = file.readLine();
                                QStringList list = line.split("%$%");
                                if(list.at(0).toInt() == t->Get_User_id() && list.at(1).toInt() == t->Get_ID())
                                {
                                }
                                else
                                {
                                    str.append(line+'\n');
                                }
                            }
                            Tfile .resize(0);
                            file << str;
                            file << t;
                            Tfile .close();
                            Tweets.close();
                            break;
                        }
                    }
                }
                Tweets.close();
            }
            if(!flag)
            {
                Checkflag = false;

            }
        }
        bool Checkflag2=true;
        while(Checkflag2)
        {
            bool flag = false;

            QFile MentionF("Mention_file.txt");
            if(!MentionF.open(QIODevice::ReadWrite|QIODevice::Text))
            {
                QMessageBox::information(this,"Warning","! File can not open.");
                return;
            }
            else
            {
                Mentions* m = new Mentions;
                QTextStream file(&MentionF);
                QStringList list;
                while(!file.atEnd())
                {
                    list = file.readLine().split("%$%");
                    for(int i = 0;i < list.at(4).split(",").size();i++)
                    {
                        if((list.at(4).split(",")).at(i).toInt() == Current_User->Get_Userid())
                        {
                            flag = true;
                            list >> m;
                            m->Erase_Who_Like(Current_User->Get_Userid());
                            break;

                        }
                    }

                    if(flag)
                    {

                        QFile MentionFF ("Mention_file.txt");
                        if(!MentionFF.open(QIODevice::ReadWrite|QIODevice::Text))
                        {
                            QMessageBox::information(this,"Warning","! File can not open.");
                            return;
                        }
                        else
                        {
                            QTextStream file(&MentionFF );
                            QString str="";
                            while(!file.atEnd())
                            {
                                QString line = file.readLine();
                                QStringList list = line.split("%$%");
                                if(m->Get_mention_id() == list.at(7).toInt()&& m->Get_User_id() == list.at(0).toInt()&&list.at(1).toInt()==m->Get_ID()/*&&
                                list.at(6).toInt()==mention_userid*/)
                                {
                                }
                                else
                                {
                                    str.append(line+'\n');
                                }
                            }
                            MentionFF .resize(0);
                            file << str;
                            file << m;
                            MentionFF.close();
                            break;
                        }

                    }

                }
                MentionF.close();
            }
            if(!flag)
            {
                Checkflag2 = false;
            }
        }
        bool Checkflag3=true;
        QFile Users ("User_file.txt");
        while(Checkflag3) // erasing follower history
        {
            bool flag = false;
            if(!Users.open(QIODevice::ReadWrite|QIODevice::Text))
            {
                QMessageBox::information(this,"Warning","! File can not open.");
                return;
            }
            else
            {
                User * U;
                QTextStream file(&Users);
                QStringList list;
                while(!file.atEnd())
                {
                    list = file.readLine().split("%$%");
                    if(list.at(0)=="A")
                    {
                        for(int i = 0;i < list.at(15).split(",").size();i++)
                        {
                            if((list.at(15).split(",")).at(i).toInt() == Current_User->Get_Userid())
                            {
                                flag = true;
                                U = new Anonymous_User();
                                list >> U;
                                U->Erase_Follower(Current_User->Get_Userid());
                                QFile Users2 ("User_file.txt");
                                if(!Users2.open(QIODevice::ReadWrite|QIODevice::Text))
                                {
                                    QMessageBox::information(0,"Warning","! File can not open.");
                                    return;
                                }
                                else
                                {
                                    QString str="";
                                    QTextStream file(&Users2);
                                    while(!file.atEnd())
                                    {
                                        QString line = file.readLine();
                                        QStringList list = line.split("%$%");
                                        if(list.at(1) != U->Get_Username())
                                        {
                                            str.append(line+'\n');
                                        }
                                    }
                                    Users2.resize(0);
                                    file << str;
                                    file << U;
                                    Users2.close();
                                }
                                break;
                            }
                        }
                    }
                    else if(list.at(0)=="P")
                    {

                        for(int i = 0;i < list.at(16).split(",").size();i++)
                        {
                            if((list.at(16).split(",")).at(i).toInt() == Current_User->Get_Userid())
                            {
                                flag = true;
                                U = new Personal_User();
                                list >> U;
                                U->Erase_Follower(Current_User->Get_Userid());
                                QFile Users2 ("User_file.txt");
                                if(!Users2.open(QIODevice::ReadWrite|QIODevice::Text))
                                {
                                    QMessageBox::information(0,"Warning","! File can not open.");
                                    return;
                                }
                                else
                                {
                                    QString str="";
                                    QTextStream file(&Users2);
                                    while(!file.atEnd())
                                    {
                                        QString line = file.readLine();
                                        QStringList list = line.split("%$%");
                                        if(list.at(1) != U->Get_Username())
                                        {
                                            str.append(line+'\n');
                                        }
                                    }
                                    Users2.resize(0);
                                    file << str;
                                    file << U;
                                    Users2.close();
                                }
                                break;
                            }
                        }

                    }
                    else
                    {
                        for(int i = 0;i < list.at(16).split(",").size();i++)
                        {
                            if((list.at(16).split(",")).at(i).toInt() == Current_User->Get_Userid())
                            {
                                flag = true;
                                U= new Organization_User();
                                list >> U;
                                U->Erase_Follower(Current_User->Get_Userid());
                                QFile Users2 ("User_file.txt");
                                if(!Users2.open(QIODevice::ReadWrite|QIODevice::Text))
                                {
                                    QMessageBox::information(0,"Warning","! File can not open.");
                                    return;
                                }
                                else
                                {
                                    QString str="";
                                    QTextStream file(&Users2);
                                    while(!file.atEnd())
                                    {
                                        QString line = file.readLine();
                                        QStringList list = line.split("%$%");
                                        if(list.at(1) != U->Get_Username())
                                        {
                                            str.append(line+'\n');
                                        }
                                    }
                                    Users2.resize(0);
                                    file << str;
                                    file << U;
                                    Users2.close();
                                }
                                break;
                            }
                        }
                    }
                }
                Users.close();
                if(!flag)
                {
                    Checkflag3 = false;
                }
            }
        }
        bool Checkflag4=true;
        while(Checkflag4) //erase following history
        {
            bool flag = false;
            if(!Users.open(QIODevice::ReadWrite|QIODevice::Text))
            {
                QMessageBox::information(this,"Warning","! File can not open.");
                return;
            }
            else
            {
                User * U;
                QTextStream file(&Users);
                QStringList list;
                while(!file.atEnd())
                {
                    list = file.readLine().split("%$%");
                    if(list.at(0)=="A")
                    {
                        for(int i = 0;i < list.at(16).split(",").size();i++)
                        {
                            if((list.at(16).split(",")).at(i).toInt() == Current_User->Get_Userid())
                            {
                                flag = true;
                                U = new Anonymous_User();
                                list >> U;
                                U->Erase_Following(Current_User->Get_Userid());
                                QFile Users2 ("User_file.txt");
                                if(!Users2.open(QIODevice::ReadWrite|QIODevice::Text))
                                {
                                    QMessageBox::information(0,"Warning","! File can not open.");
                                    return;
                                }
                                else
                                {
                                    QString str="";
                                    QTextStream file(&Users2);
                                    while(!file.atEnd())
                                    {
                                        QString line = file.readLine();
                                        QStringList list = line.split("%$%");
                                        if(list.at(1) != U->Get_Username())
                                        {
                                            str.append(line+'\n');
                                        }
                                    }
                                    Users2.resize(0);
                                    file << str;
                                    file << U;
                                    Users2.close();
                                }
                                break;
                            }
                        }
                    }
                    else if(list.at(0)=="P")
                    {

                        for(int i = 0;i < list.at(17).split(",").size();i++)
                        {
                            if((list.at(17).split(",")).at(i).toInt() == Current_User->Get_Userid())
                            {
                                flag = true;
                                U = new Personal_User();
                                list >> U;
                                U->Erase_Following(Current_User->Get_Userid());
                                QFile Users2 ("User_file.txt");
                                if(!Users2.open(QIODevice::ReadWrite|QIODevice::Text))
                                {
                                    QMessageBox::information(0,"Warning","! File can not open.");
                                    return;
                                }
                                else
                                {
                                    QString str="";
                                    QTextStream file(&Users2);
                                    while(!file.atEnd())
                                    {
                                        QString line = file.readLine();
                                        QStringList list = line.split("%$%");
                                        if(list.at(1) != U->Get_Username())
                                        {
                                            str.append(line+'\n');
                                        }
                                    }
                                    Users2.resize(0);
                                    file << str;
                                    file << U;
                                    Users2.close();
                                }
                                break;
                            }
                        }

                    }
                    else
                    {
                        for(int i = 0;i < list.at(17).split(",").size();i++)
                        {
                            if((list.at(17).split(",")).at(i).toInt() == Current_User->Get_Userid())
                            {
                                flag = true;
                                U= new Organization_User();
                                list >> U;
                                U->Erase_Following(Current_User->Get_Userid());
                                QFile Users2 ("User_file.txt");
                                if(!Users2.open(QIODevice::ReadWrite|QIODevice::Text))
                                {
                                    QMessageBox::information(0,"Warning","! File can not open.");
                                    return;
                                }
                                else
                                {
                                    QString str="";
                                    QTextStream file(&Users2);
                                    while(!file.atEnd())
                                    {
                                        QString line = file.readLine();
                                        QStringList list = line.split("%$%");
                                        if(list.at(1) != U->Get_Username())
                                        {
                                            str.append(line+'\n');
                                        }
                                    }
                                    Users2.resize(0);
                                    file << str;
                                    file << U;
                                    Users2.close();
                                }
                                break;
                            }
                        }
                    }
                }
                Users.close();
                if(!flag)
                {
                    Checkflag4 = false;
                }
            }
        }
        if(!Users.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            QMessageBox::information(0,"Warning","! File can not open.");
            return;
        }
        else
        {
            QString str="";
            QTextStream file(&Users);
            while(!file.atEnd())
            {
                 QString line = file.readLine();
                 QStringList list = line.split("%$%");
                 if(list.at(1) != Current_User->Get_Username())
                 {
                    str.append(line+'\n');
                 }
            }
            Users.resize(0);
            file << str;
            Users.close();
        }
        Current_User = nullptr;
        emit Send_Current_User(Current_User);
        this->close();
    }

}

