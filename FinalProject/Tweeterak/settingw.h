#ifndef SETTINGW_H
#define SETTINGW_H

#include <QDialog>
#include <QPixmap>
#include <QIcon>
#include <QColorDialog>
#include <QColor>
#include <QPalette>
#include <QDebug>
#include <QFileDialog>
#include <QImageReader>
#include <QByteArray>
#include <QDir>
#include "user.h"
#include "sha256.h"
namespace Ui {
class SettingW;
}

class SettingW : public QDialog
{
    Q_OBJECT

public:
    explicit SettingW(QWidget *parent = nullptr);
    void Get_User(User* user);
    void Selected_color(QColor color);
    void Picture_Path(QString path);
    ~SettingW();
signals:
    void Send_Current_User(User*);
private slots:
    void Validator(QString& message,QValidator::State &st);
    void on_btn_change_clicked();

    void on_btn_headerchange_clicked();

    void on_btn_changepic_clicked();

    void on_btn_delaccount_clicked();

private:
    Ui::SettingW *ui;
    User * Current_User;
    QColor Selected_Color;
    QString picture_path;
};

#endif // SETTINGW_H
