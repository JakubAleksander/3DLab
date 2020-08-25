QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Task
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

SRC_DIR = src

SOURCES += \
        $$SRC_DIR/main.cpp \
        $$SRC_DIR/mainwindow.cpp

HEADERS += \
        $$SRC_DIR/mainwindow.h

FORMS += \
        $$SRC_DIR/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
