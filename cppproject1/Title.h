#ifndef TITLE_H
#define TITLE_H

#include "Main.h"
#include "Accessories.h"
#include <string>
#include <QMainWindow>
#include <QAction>
#include <QCoreApplication>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class Title : public QMainWindow, Accessories {
    Q_OBJECT
public:
    Title(QWidget *parent = NULL): QMainWindow(parent){
        this->setWindowTitle("Welcome to currency exchange shop");
        this->resize(1000, 600);
        this->setStyleSheet("background-color:skyblue;");
        this->setAutoFillBackground(true);

        pixLogo.load(pathLogo);
        lblLogo = new QLabel(this);
        lblLogo->setGeometry(350, 100, 300, 300);
        lblLogo->setPixmap(pixLogo);

        pbLogo = new QPushButton("START", this);
        pbLogo->setGeometry(350, 410, 300, 50);
        pbLogo->setStyleSheet("background-color:white;");
        QObject::connect(pbLogo, SIGNAL(clicked()), this, SLOT(pbLogoClicked()));
    }

public slots:
    void pbLogoClicked(){
            Main *widget = new Main();
            this->hide();
            widget->show();

     }
};


#endif // TITLE_H

