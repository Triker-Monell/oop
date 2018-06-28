#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>
#include "qt_levelmain.h"
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include "qt_level.h"
#include "qt_action.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT
private:


    QToolBar* toolbar;
    QStatusBar* statusbar;
    void initAction();
    void initTarget(); //set target
    void initMenu();
private slots:
    void back2m(); //back to main (delete all except  main)
    void back2u(); //back to upperlevel (delete latest level)
public slots:
    void addLevel(Level* level);
    void on_action(Action* checkedone);
    void searchac_action();
public:
    std::vector<Level*> stack;
    QWidget* widget; //central


    QMenu* operation;
    //QAction* startac;
    //QMenu* back;
    Action* back2mainac;
    Action* back2upperac;

    QMenu* mode;
    Action* rankac;
    Action* searchac;

    QMenu* target;
    QMenu* web;
    QMenu* object;
    const static int webnum=3;
    enum{
        DouBan,RottenTomatoes,IMDB
    };
    //order  douban rottentomatoes imdb...
    const static int objnum=2;
    enum{
        Movie,Tv
    };
    //order Movie Tv
    Action* webs[webnum];
    Action* objs[objnum];
    int webindex; //default Douban 0
    int objindex; //default Movie 0


    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
