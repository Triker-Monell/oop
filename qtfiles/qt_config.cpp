#include "qt_config.h"

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

Details* Config::getDetails(QWidget *_central, QWidget *mwin){
    MainWindow* window=dynamic_cast<MainWindow*>(mwin);
    int checknum=0;
    while(checknum<MainWindow::objnum){
        if(window->objs[checknum]->isChecked())
            break;
        checknum++;
    }
    Details* back;
    switch(checknum){
    case MainWindow::Movie: back=new Movie(_central,mwin);break;
    case MainWindow::Tv: /**/;break;
    }

    return back;
}

ScoreWidget* Config::getScoreWidget(QWidget *mwin){
    MainWindow* window=dynamic_cast<MainWindow*>(mwin);
    int checknum=0;
    while(checknum<MainWindow::webnum){
        if(window->webs[checknum]->isChecked())
            break;
        checknum++;
    }
    ScoreWidget* back;
    switch(checknum){
    case MainWindow::DouBan: back=new DBSWidget(window);break;
    case MainWindow::IMDB: /**/;break;
    case MainWindow::RottenTomatoes: /**/;break;
    }
    return back;
}
