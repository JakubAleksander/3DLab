QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtScriptRunner
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

OTHER_FILES += \
        $$PWD/scripts

defineTest(copyScripts) {
    files = $$1
    dir = $$2

    for(file, files){
        QMAKE_POST_LINK += $$QMAKE_COPY_DIR $$shell_quote($$file) $$shell_quote($$dir)
    }
    export(QMAKE_POST_LINK)
}

copyScripts($$OTHER_FILES, $$OUT_PWD)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
