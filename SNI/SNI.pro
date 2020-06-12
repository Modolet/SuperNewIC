QT       += core gui
QT       += network
QT       += sql
QT       += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    allstuscore.cpp \
    changepasswd.cpp \
    changeusericon.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    network.cpp \
    stu_accessport.cpp \
    stu_mainwindow.cpp \
    stu_sqlmodel.cpp \
    studentexperimentalresult.cpp \
    studentlist.cpp \
    studentlistbuddy.cpp

HEADERS += \
    allstuscore.h \
    changepasswd.h \
    changeusericon.h \
    const.h \
    login.h \
    mainwindow.h \
    network.h \
    stu_accessport.h \
    stu_mainwindow.h \
    stu_sqlmodel.h \
    studentexperimentalresult.h \
    studentlist.h \
    studentlistbuddy.h

FORMS += \
    allstuscore.ui \
    changepasswd.ui \
    changeusericon.ui \
    login.ui \
    mainwindow.ui \
    stu_accessport.ui \
    stu_mainwindow.ui \
    studentexperimentalresult.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc \
    qss.qrc

RC_ICONS = "ICON.ico"
RC_LANG = 0x0004
VERSION = 0.8.0.2
QMAKE_TARGET_PRODUCT="超新芯"
QMAKE_TARGET_COMPANY="超新芯团队"
QMAKE_TARGET_DESCRIPTION="超新芯管理软件"
QMAKE_TARGET_COPYRIGHT="Copyright  2020 超新芯团队 All rights reserved"
