#ifndef LEVELRANK_H
#define LEVELRANK_H

#include <QObject>
#include <QWidget>
#include "qt_level.h"
#include <QListWidget>
#include <QLabel>
#include <QComboBox>
#include <QListWidgetItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
class LevelRank : public Level
{
    Q_OBJECT
protected:
    QListWidget* list;
    QPushButton* scorebtn; // sort by score   high score first
    QPushButton* datebtn; // sort by date   early first
    QLabel* typelabel;// type_label
    QComboBox* typecombobox; //select type
    QLabel* imagelabel; //image   jpg
    QGridLayout* glayout;
    void pushlayout();
    //Object!!

public slots:
    void changelist(); //change list according btn and combobox
    void changeimage(QListWidgetItem* item); //choose one item and show its image
    void doubleclicked(QListWidgetItem* item); //double click one item and go to next level
public:
    LevelRank(QWidget* _central,QWidget* parent);
    ~LevelRank();
    void show();
    void hide();
};

#endif // LEVELRANK_H
