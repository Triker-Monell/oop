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
    qt_scorewidget.cpp \
    qt_imdbswidget.cpp \
    qt_rtswidget.cpp \
    BaseData/Writer.cpp \
    BaseData/Type.cpp \
    BaseData/Studio.cpp \
    BaseData/Similar.cpp \
    BaseData/Sex.cpp \
    BaseData/Season.cpp \
    BaseData/Runtime.cpp \
    BaseData/RottenTomatoesScore.cpp \
    BaseData/Rated.cpp \
    BaseData/Place.cpp \
    BaseData/OfficialSites.cpp \
    BaseData/Name.cpp \
    BaseData/LeadingActor.cpp \
    BaseData/Language.cpp \
    BaseData/Job.cpp \
    BaseData/Intro.cpp \
    BaseData/IMDBScore.cpp \
    BaseData/Family.cpp \
    BaseData/Episodes.cpp \
    BaseData/DouBanScore.cpp \
    BaseData/Director.cpp \
    BaseData/Date.cpp \
    BaseData/Constellation.cpp \
    BaseData/Boxing.cpp \
    BaseData/Format/RTSio.cpp \
    BaseData/Format/IOFormat.cpp \
    BaseData/Format/IMDBSio.cpp \
    BaseData/Format/DBSio.cpp \
    BaseData/Format/DateFormat.cpp \
    Catcher/BaseCatcher.cpp \
    Catcher/IMDB_by_movies.cpp \
    ObjRanking/BaseObject.cpp \
    ObjRanking/Ranking.cpp \
    ObjRanking/Strategies.cpp \
    Catcher/Douban_by_movies.cpp \
    Catcher/RottenTomatoes_by_movies.cpp \
    qt_tv.cpp \
    Catcher/RottenTomatoes_by_people.cpp \
    Catcher/IMDB_by_people.cpp \
    BaseData/BirthInfo.cpp \
    Catcher/RottenTomatoes_by_TV.cpp \
    Catcher/IMDB_by_TV.cpp \
    BaseData/Producer.cpp \
    Catcher/Douban_by_TV.cpp \
    Catcher/RottenTomatoes_by_toplist.cpp \
    Catcher/IMDB_by_toplist.cpp \
    Catcher/Douban_by_toplist.cpp

HEADERS += \
    qt_action.h \
    qt_config.h \
    qt_dbswidget.h \
    qt_details.h \
    qt_label.h \
    qt_level.h \
    qt_person.h \
    qt_movie.h \
    qt_mainwindow.h \
    qt_levelsearch.h \
    qt_levelrank.h \
    qt_levelmain.h \
    qt_scorewidget.h \
    qt_imdbswidget.h \
    qt_rtswidget.h \
    BaseData/Writer.h \
    BaseData/Type.h \
    BaseData/Studio.h \
    BaseData/Similar.h \
    BaseData/Sex.h \
    BaseData/Season.h \
    BaseData/Score.h \
    BaseData/Runtime.h \
    BaseData/RottenTomatoesScore.h \
    BaseData/Rated.h \
    BaseData/Place.h \
    BaseData/People.h \
    BaseData/OfficialSites.h \
    BaseData/Name.h \
    BaseData/LeadingActor.h \
    BaseData/Language.h \
    BaseData/Job.h \
    BaseData/Intro.h \
    BaseData/IMDBScore.h \
    BaseData/Image.h \
    BaseData/Family.h \
    BaseData/Episodes.h \
    BaseData/DouBanScore.h \
    BaseData/Director.h \
    BaseData/Date.h \
    BaseData/Constellation.h \
    BaseData/Boxing.h \
    BaseData/BaseData.h \
    BaseData/allBaseData.h \
    BaseData/Format/RTSio.h \
    BaseData/Format/IOFormat.h \
    BaseData/Format/IMDBSio.h \
    BaseData/Format/DBSio.h \
    BaseData/Format/DateFormat.h \
    Catcher/BaseCatcher.h \
    Catcher/Douban_by_movies.h \
    Catcher/Douban_by_people.h \
    Catcher/Douban_by_toplist.h \
    Catcher/Douban_by_TV.h \
    Catcher/IMDB_by_movies.h \
    Catcher/IMDB_by_people.h \
    Catcher/IMDB_by_toplist.h \
    Catcher/IMDB_by_TV.h \
    Catcher/RottenTomatoes_by_movies.h \
    Catcher/RottenTomatoes_by_people.h \
    Catcher/RottenTomatoes_by_toplist.h \
    Catcher/RottenTomatoes_by_TV.h \
    ObjRanking/BaseObject.h \
    ObjRanking/MovieObject.h \
    ObjRanking/PersonObject.h \
    ObjRanking/Ranking.h \
    ObjRanking/Strategies.h \
    ObjRanking/TVObject.h \
    BaseData/allBaseData.h \
    Catcher/allCatcher.h \
    ObjRanking/allObj.h \
    Catcher/RottenTomatoes_by_movies.h \
    qt_tv.h \
    BaseData/BirthInfo.h \
    BaseData/Producer.h \
    BaseData/path.h

RESOURCES += \
    webimage.qrc

DISTFILES += \
    Catcher/IMDB_by_movies.py \
    Catcher/Douban_by_movies.py \
    Catcher/RottenTomatoes_by_movies.py \
    Catcher/RottenTomatoes_by_people.py \
    Catcher/IMDB_by_people.py \
    Catcher/IMDB_by_TV.py \
    Catcher/RottenTomatoes_by_TV.py \
    Catcher/Douban_by_TV.py \
    Catcher/RottenTomatoes_by_toplist.py \
    Catcher/IMDB_by_toplist.py \
    Catcher/Douban_by_toplist.py

INCLUDEPATH += -I/usr/include/python2.7 -I/usr/include/x86_64-linux-gnu/python2.7  -fno-strict-aliasing -Wdate-time -D_FORTIFY_SOURCE=2 -g -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes
LIBS += -L/usr/lib/python2.7/config-x86_64-linux-gnu -L/usr/lib -lpython2.7 -lpthread -ldl  -lutil -lm  -Xlinker -export-dynamic -Wl,-O1 -Wl,-Bsymbolic-functions  -std=c++11
