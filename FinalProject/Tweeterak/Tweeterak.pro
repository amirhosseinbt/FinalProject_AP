QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Date.cpp \
    Tweet.cpp \
    Twitterak.cpp \
    a_signup.cpp \
    choose_a_type.cpp \
    hash_tagform.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mention.cpp \
    o_signup.cpp \
    p_signup.cpp \
    settingw.cpp \
    show_account.cpp \
    tweetwindow.cpp \
    user.cpp

HEADERS += \
    Date.hpp \
    Tweet.hpp \
    Twitterak.hpp \
    a_signup.h \
    choose_a_type.h \
    hash_tagform.h \
    login.h \
    mainwindow.h \
    mention.h \
    o_signup.h \
    p_signup.h \
    settingw.h \
    show_account.h \
    tweetwindow.h \
    user.h

FORMS += \
    a_signup.ui \
    choose_a_type.ui \
    hash_tagform.ui \
    login.ui \
    mainwindow.ui \
    mention.ui \
    o_signup.ui \
    p_signup.ui \
    settingw.ui \
    show_account.ui \
    tweetwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
