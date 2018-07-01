#ifndef LEVELMAIN_H
#define LEVELMAIN_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include "qt_level.h"
#include "qt_levelsearch.h"
#include <QVBoxLayout>
class LevelMain : public Level
{
    Q_OBJECT
private:
    QPushButton* rankbtn;
    QPushButton* searchbtn;
    QVBoxLayout* layout;
    void pushlayout(); //set layout again and set size
public slots:
    void rankbtn_clicked();
    void searchbtn_clicked();
public:
    LevelMain(QWidget* _central,QWidget* parent);
    void show();
    void hide();
    ~LevelMain();
};

#endif // LEVELMAIN_H
