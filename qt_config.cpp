#include "qt_config.h"
#include "qt_tv.h"
#include "qt_rtswidget.h"
Config Config::_instance;
QString Config::getSearchTitle(QWidget* mwin){
    QString str=tr("");
    MainWindow* window=dynamic_cast<MainWindow*>(mwin);
    int checknum=0;
    while(checknum<MainWindow::objnum){
        if(window->objs[checknum]->isChecked())
            break;
        checknum++;
    }
    switch(checknum){
    case MainWindow::Movie: str=tr("Movie");break;
    case MainWindow::Tv: str=tr("Tv");break;
    }
    return str;
}

Details* Config::getDetails(QString _name, QWidget *_central, QWidget *mwin){
    MainWindow* window=dynamic_cast<MainWindow*>(mwin);
    int checknum=0;
    while(checknum<MainWindow::objnum){
        if(window->objs[checknum]->isChecked())
            break;
        checknum++;
    }
    Details* back;
    switch(checknum){
    case MainWindow::Movie: back=new Movie(_name,_central,mwin);break;
    case MainWindow::Tv: back=new Tv(_name,_central,mwin);break;
    }

    return back;
}

ScoreWidget* Config::getScoreWidget(const Score *_score, QWidget *mwin){
    MainWindow* window=dynamic_cast<MainWindow*>(mwin);
    int checknum=0;
    while(checknum<MainWindow::webnum){
        if(window->webs[checknum]->isChecked())
            break;
        checknum++;
    }
    ScoreWidget* back=nullptr;
    switch(checknum){
    case MainWindow::DouBan: back=new DBSWidget(_score,window);break;
    case MainWindow::IMDB: back=new IMDBSWidget(_score,window);break;
    case MainWindow::RottenTomatoes: back=new RTSWidget(_score,window);break;
    }
    return back;
}


BaseStrategy* Config::getStrategy(QWidget* mwin,bool isPeople){
    MainWindow* window=dynamic_cast<MainWindow*>(mwin);

    if(isPeople){
        int judgeweb=0;
        while(judgeweb<MainWindow::webnum){
            qDebug()<<judgeweb << " " << MainWindow::webnum;
            for(int i=0;i<webnum;i++){
                if(window->webs[i]->isChecked())
                    qDebug() << "number " << i << " is checked";
            }
            if(window->webs[judgeweb]->isChecked())
                break;
            judgeweb++;
        }
        BaseStrategy* back=nullptr;
        switch(judgeweb){
        case MainWindow::DouBan: back=nullptr; //不支持
        case MainWindow::IMDB: back=new  Imdb_people_Strategy;break;
        case MainWindow::RottenTomatoes: back = new Tomato_people_Strategy;break;
        }
        return back;
    }



    int checkweb=0;
    int checkobj=0;
    while(checkweb<MainWindow::webnum){
        if(window->webs[checkweb]->isChecked())
            break;
        checkweb++;
    }
    while(checkobj<MainWindow::objnum){
        if(window->objs[checkobj]->isChecked())
            break;
        checkobj++;
    }

    BaseStrategy* back=nullptr;

    switch(checkweb){
    case MainWindow::DouBan:{
            switch(checkobj){
            case MainWindow::Movie: back=new Douban_movies_Strategy;break;
            case MainWindow::Tv: back=new Douban_TV_Strategy;break;
            }
        break;
        }
    case MainWindow::IMDB:{
            switch(checkobj){
            case MainWindow::Movie: back=new Imdb_movies_Strategy;break;
            case MainWindow::Tv: back=new Imdb_TV_Strategy;break;
            }
        break;
        }
    case MainWindow::RottenTomatoes:{
            switch(checkobj){
            case MainWindow::Movie: back=new Tomato_movies_Strategy;break;
            case MainWindow::Tv: back=new Tomato_TV_Strategy;break;
            }
        break;
        }
    }

    return back;
}


void Config::setAction(QWidget *mwin, bool bl){
    MainWindow* window=dynamic_cast<MainWindow*>(mwin);
    for(int i=0;i<MainWindow::webnum;i++){
        window->webs[i]->setEnabled(bl);
    }
    for(int i=0;i<MainWindow::objnum;i++){
        window->objs[i]->setEnabled(bl);
    }
}


bool Config::peoplesupportJugde(QWidget *mwin){
    MainWindow* window=dynamic_cast<MainWindow*>(mwin);
    if(window->webs[MainWindow::DouBan]->isChecked())
        return false;
    return true;
}
