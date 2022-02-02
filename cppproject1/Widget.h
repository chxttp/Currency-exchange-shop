#ifndef WIDGET_H
#define WIDGET_H
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


class Widget : public QMainWindow {
    Q_OBJECT
public:
    Widget(QWidget *parent = NULL): QMainWindow(parent){
        this->setWindowTitle("Currency shop");
        this->resize(1000,600);
        this->setStyleSheet("background-color:white;");
        this->setAutoFillBackground( true );
        pix1.load(path1 + "pic1.jpg");
        label1= new QLabel(this);
        label1->setGeometry(380,90,600,500);
        label1->setPixmap(pix1);
        pix2.load(path1+ "pic2.jpg");
        label2= new QLabel(this);
        label2->setGeometry(180,180,200,340);
        label2->setPixmap(pix2);
        label2->setVisible(false);
        pix3.load(path1+ "pic3.jpg");
        label3= new QLabel(this);
        label3->setGeometry(180,180,200,340);
        label3->setPixmap(pix3);
        label3->setVisible(false);
        pix4.load(path1+ "pic4.jpg");
        label4= new QLabel("            WELCOME",this);
        label4->setStyleSheet("background-color:red;");
        label4->setGeometry(750,40,200,100);
        //label4->setPixmap(pix4);
        box1=new QGroupBox("Shop assistance->",this);
        box1->setStyleSheet("background-color:pink;");
        box2= new QGroupBox("Please select",this);
        box2->setStyleSheet("background-color:pink;");
        menu1();
    }
    void menu1(){
        srand (time(NULL));
        int count = rand() % 2;
        box1->setGeometry(530,90,200,100);
        box2->setGeometry(320,100,180,130);
        l1 = new QLabel("");
        Grid1 = new QGridLayout;
        Grid1->addWidget(l1, 0, 0);
        if(count == 0){
            label2->setVisible(true);
            label3->setVisible(false);
            l1->setText("Hello Ma'am\nMay i help you?");
        }
        else{
            label2->setVisible(false);
            label3->setVisible(true);
            l1->setText("Hello Sir\nMay i help you?");
        }
        box1->setLayout(Grid1);
        l2 = new QLabel("");
        l2->setText("1.)Buy\n2.)Sell");
        cb1= new QComboBox(this);
        cb1->addItem("Select:");
        cb1->addItem("1.)Buy");
        cb1->addItem("2.)Sell");
        Grid2 = new QGridLayout;
        Grid2->addWidget(l2,0,0);
        Grid2->addWidget(cb1,1,0);
        box2->setLayout(Grid2);
        QObject::connect(cb1, SIGNAL(currentIndexChanged(int)), this, SLOT(select1(int)));
    }
    void menu2(int n){
        box1->setGeometry(530,90,200,100);
        box2->setGeometry(320,100,180,130);
        if(n == 1)
            l1 -> setText("Buy?");
        else
            l1->setText("Sell?");
        cb2= new QComboBox(this);
        cb2->addItem("Select:");
        cb2->addItem("1.)USD");
        cb2->addItem("2.)GBP");
        cb2->addItem("3.)EUR");
        Grid2->layout()->destroyed();
        l2 = new QLabel("1.USD",this);
        l3 = new QLabel("2.GBP",this);
        l4 = new QLabel("3.EUR",this);
        Grid2->addWidget(l2, 0, 0);
        Grid2->addWidget(l3,1,0);
        Grid2->addWidget(l4,2,0);
        Grid2->addWidget(cb2,3,0);
        box2->setLayout(Grid2);
        QObject::connect(cb2, SIGNAL(currentIndexChanged(int)), this, SLOT(select2(int)));
    }
    void menu3(int n){
        box1->setGeometry(530,90,200,100);
        box2->setGeometry(320,100,180,130);
        if(m1 == 1)
            l1 -> setText("Buy " + sl[n - 1]);
        else
            l1 -> setText("Sell " + sl[n - 1]);
        txt1 = new QTextEdit("10", this);
        txt1->setAlignment(Qt::AlignCenter);
        pb1 = new QPushButton("OK", this);
        Grid2->layout()->destroyed();
        l5 = new QLabel(sl[n - 1], this);
        cb2->setVisible(false);
        Grid2->addWidget(l5, 0, 0);
        Grid2->addWidget(txt1,1,0);
        Grid2->addWidget(pb1, 2, 0);
        box2->setLayout(Grid2);
        QObject::connect(pb1, SIGNAL(clicked()), this, SLOT(select3()));
    }
public slots:
    void select1(int index){
        if(index == 1 || index ==2){
            m1=index;
            menu2(index);
        }
    }
    void select2(int index){
        if(index >= 1 && index <= 3){
            m2 = index;
            menu3(index);
        }
    }
    void select3() {
        QMessageBox msgBox;
        int count = 0;
        QString s1 = txt1->toPlainText();
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] >= '0' && s1[i] <= '9') {
                count++;
            }
        }
        if(count == s1.length()) {
            msgBox.setText("OK " + ch[m1 - 1] + " " + sl[m2 - 1] + " " + txt1->toPlainText());
        }
        else {
            msgBox.setText("Input only number");
            txt1->setText("10");
            txt1->setAlignment(Qt::AlignCenter);
        }
        msgBox.exec();
    }





private:
    QLabel *label1,*label2,*label3,*label4,*l1,*l2, *l3, *l4, *l5;
    QPixmap pix1, pix2, pix3,pix4;
    QString path1 = QCoreApplication::applicationDirPath() + "/pic/";
    QGroupBox *box1,*box2;
    QComboBox *cb1,*cb2, *cb3;
    QGridLayout *Grid1,*Grid2;
    QTextEdit *txt1;
    QPushButton *pb1;
    int m1, m2;
    QStringList sl{"USD", "GBP", "EUR" }, ch{"Buy", "Sell"};
};

#endif // WIDGET_H
