#ifndef CONFIG_H
#define CONFIG_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "qt_mainwindow.h"
#include "qt_movie.h"
#include "qt_dbswidget.h"
#include "qt_imdbswidget.h"
#include "ObjRanking/allObj.h"
class Config : public QObject
{
    Q_OBJECT
private:
    friend class mainwindow;

    Config(const Config&)=delete;
    void operator=(const Config&)=delete;

    Config():QObject(nullptr){}
    static Config _instance;


public:
    static Config& instance(){
     return _instance;
    }

    static const int webnum=3;
    static const int objnum=2;

    QString getSearchTitle(QWidget *mwin);

    Details* getDetails(QString _name,QWidget *_central,QWidget* _mwin);

    ScoreWidget* getScoreWidget(QWidget* mwin);

    BaseStrategy* getStrategy(QWidget* mwin, bool isPeople=false);

    void setAction(QWidget* mwin,bool bl); //set all action cant be triggered or can
signals:

public slots:
};
#endif // CONFIG_H
