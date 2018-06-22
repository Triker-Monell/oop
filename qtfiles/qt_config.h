#ifndef CONFIG_H
#define CONFIG_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "qt_mainwindow.h"
#include "qt_movie.h"
#include "qt_dbswidget.h"
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

    Details* getDetails(QWidget *_central,QWidget* _mwin);

    ScoreWidget* getScoreWidget(QWidget* mwin);
signals:

public slots:
};
#endif // CONFIG_H
