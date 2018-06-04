cmake_minimum_required(VERSION 3.9)
project(MICP)

set(CMAKE_CXX_STANDARD 11)

add_executable(MICP main.cpp BaseCatcher.h Douban_by_movies.h IMDB_by_movies.h RottenTomatoes_by_movies.h
        BaseCatcher.cpp IMDB_by_movies.cpp Douban_by_movies.cpp RottenTomatoes_by_movies.cpp allHeadFiles.h BaseData.h
        BaseScore.h BriefIntroduction.h BriefIntroduction.cpp DoubanScore FilmMaker.cpp FilmMaker.h
        Language.cpp Language.h MovieType.cpp MovieType.h Person.h RDformat.cpp RDformat.h ReleaseDate.cpp
        ReleaseDate.h RottenTomatoesScore.h Runtime.cpp Runtime.h Score.h TypeLanguage.cpp TypeLanguage.h Douban_by_people.cpp
        Douban_by_people.h Douban_by_TV.cpp Douban_by_TV.h IMDB_by_people.cpp IMDB_by_people.h
        IMDB_by_TV.cpp IMDB_by_TV.h RottenTomatoes_by_people.cpp RottenTomatoes_by_people.h
        RottenTomatoes_by_TV.cpp RottenTomatoes_by_TV.h Douban_by_toplist.cpp Douban_by_toplist.h
        IMDB_by_toplist.cpp IMDB_by_toplist.h RottenTomatoes_by_toplist.cpp RottenTomatoes_by_toplist.h
        RottenTomatoes_by_TV.py RottenTomatoes_by_toplist.py RottenTomatoes_by_people.py RottenTomatoes_by_movies.py
        IMDB_by_movies.py IMDB_by_people.py IMDB_by_toplist.py IMDB_by_TV.py Douban_by_movies.py Douban_by_TV.py
        Douban_by_toplist.py)