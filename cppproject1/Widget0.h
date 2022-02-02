#ifndef WIDGET0_H
#define WIDGET0_H
#include "Widget.h"
#include <QLabel>
#include <QMainWindow>
#include <QAction>
#include <QPushButton>
#include <QCoreApplication>
#include <QTextEdit>
#include <QComboBox>
#include <QGroupBox>
#include <stdlib.h>
#include <time.h>
#include <QGridLayout>
#include <QMessageBox>
class Widget0 : public QMainWindow {
    Q_OBJECT
public:
    Widget0(QWidget *parent = NULL): QMainWindow(parent){
        this->setWindowTitle("Welcome to currency shop");
        this->resize(1000,600);
        this->setStyleSheet("background-color:red;");
        this->setAutoFillBackground( true );
        pix1.load(path1 + "bg.jpg");
        label1= new QLabel(this);
        label1->setGeometry(150,40,600,500);
        label1->setPixmap(pix1);
        pb1= new QPushButton("START",this);
        pb1->setGeometry(150,500,200,50);
        pb1->setStyleSheet("background-color:white;");
        QObject::connect(pb1, SIGNAL(clicked()), this, SLOT(pb1Clicked()));

    }

public slots:
    void pb1Clicked(){
        Widget *widget = new Widget();
        this->hide();
        widget->show();


    }





private:
    QLabel *label1;
    QPixmap pix1;
    QString path1 = QCoreApplication::applicationDirPath() + "/pic/";
    QPushButton *pb1;


};

#endif // WIDGET0_H

