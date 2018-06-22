#-------------------------------------------------
#
# Project created by QtCreator 2018-06-12T01:19:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InfoCS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    qt_action.cpp \
    qt_config.cpp \
    qt_dbswidget.cpp \
    qt_label.cpp \
    qt_level.cpp \
    qt_details.cpp \
    qt_levelmain.cpp \
    qt_levelrank.cpp \
    qt_levelsearch.cpp \
    qt_main.cpp \
    qt_person.cpp \
    qt_movie.cpp \
    qt_mainwindow.cpp \
    qt_scorewidget.cpp

HEADERS += \
    qt_action.h \
    qt_config.h \
    qt_dbswidget.h \
    qt_details.h \
    qt_label.h \
    qt_level.h \
    qt_scorewidget.h \
    qt_person.h \
    qt_movie.h \
    qt_mainwindow.h \
    qt_levelsearch.h \
    qt_levelrank.h \
    qt_levelmain.h

RESOURCES += \
    webimage.qrc

DISTFILES +=

INCLUDEPATH += -I/usr/include/python2.7/
LIBS += -L /usr/include/python2.7/ -lpython2.7
