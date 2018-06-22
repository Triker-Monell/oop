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
struct simple{  //simple data    cannot click
    QLabel* data;
    //score;
};

struct complex{ //complex data   can click
    QLabel* type;
    std::vector<Label*> data; //use special label
    QPushButton* more; //more call a dialog
};
class Details : public Level
{
    Q_OBJECT
private:
    bool isScore; //have Score Module?

    void inputdata(); //put data into widgets
    void pushlayout();
protected:
    //object

    ScoreWidget* score; //if isScore!=true then score=nullptr

    std::vector<simple> spvec;  //simple data vector
    std::vector<complex> cpvec;  //complex data vector
    int shownum=4; //complex show num

    QLabel* poster;
    QPushButton* moreimage; //more image  call a dialog with images
    QPushButton* moreintro; //Person!!!  more introduction call dialog

    QGridLayout* glayout;

public:
    Details(QWidget* _central,QWidget* parent,bool _isScore);  //have Score Module?
    void show()final;
    void hide()final;
    ~Details();
};

#endif // DETAILS_H
