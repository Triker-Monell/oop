#ifndef LEVELSEARCH_H
#define LEVELSEARCH_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "qt_level.h"
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "qt_action.h"
#include <QLabel>
class MainWindow;
class LevelSearch : public Level
{
    Q_OBJECT
private:
    QPushButton* name; //text according  the target obj
    QPushButton* personname;
    QLineEdit* searchline;
    QPushButton* confirmbtn;
    QLabel* tips; //error tips

    QHBoxLayout* hlayout;
    QVBoxLayout* vlayout;
    void pushlayout(); //set layout and size
public:
    LevelSearch(QWidget* _central,QWidget* parent);
    void show();
    void hide();
    ~LevelSearch();

public slots:
    void name_change(Action* ac); //when antion obj is triggered,name should change by it

    void name_clicked();
    void person_clicked();

    void search_clicked();
};

#endif // LEVELSEARCH_H
