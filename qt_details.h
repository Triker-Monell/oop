#ifndef DETAILS_H
#define DETAILS_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include "qt_level.h"
#include <vector>
#include "qt_label.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QImage>
#include <QGridLayout>
#include "qt_dbswidget.h"
#include "ObjRanking/allObj.h"
struct simple{  //simple data    cannot click
    QLabel* data;
};

struct complex{ //complex data   can click
    QLabel* type;
    std::vector<Label*> data; //use special label
    QPushButton* more; //more call a dialog
};
class Details : public Level
{
    Q_OBJECT
protected:
    //object
    BaseObject* obj;

    ScoreWidget* score; //if isScore!=true then score=nullptr

    std::vector<simple> spvec;  //simple data vector
    std::vector<complex> cpvec;  //complex data vector
    int shownum=4; //complex show num

    QLabel* poster;
    QPushButton* moreimage; //tips

    QPushButton* moreintro; //old

    QGridLayout* glayout;

    bool isScore; //have Score Module?
    void inputdata(); //put data into widgets
    void pushlayout();

    std::string image_name_filter(std::string prev); //把空格变为_ 便于找照片
public:
    Details(QWidget* _central,QWidget* parent,bool _isScore);  //have Score Module?
    void show()final;
    void hide()final;
    ~Details();

public slots:
    void image_triggerd();
};

#endif // DETAILS_H
