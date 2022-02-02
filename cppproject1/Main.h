#ifndef MAIN_H
#define MAIN_H

#include "Accessories.h"
#include <QCoreApplication>
#include <QApplication>

#include <QMainWindow>
#include <QAction>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QComboBox>
#include <QGroupBox>
#include <stdlib.h>
#include <time.h>
#include <QGridLayout>
#include <QMessageBox>
#include <QTimer>
#include <QThread>
#include <QFile>
#include <QDebug>
#include <QSettings>
#include <QStringList>
#include <QDate>
#include <QDesktopServices>

class Main : public QMainWindow, Accessories {
    Q_OBJECT
public:
    Main(QWidget *parent = NULL): QMainWindow(parent) {
        this->setWindowTitle("Currency exchange shop");
        this->resize(1000, 600);
        this->setStyleSheet("background-color:white;");
        this->setAutoFillBackground(true);

        step0();
    }
    void declare() {
        pixSeller.load(pathSeller);
        lblSeller = new QLabel(this);
        lblSeller->setGeometry(380, 90, 600, 500);
        lblSeller->setPixmap(pixSeller);

        pixWomen.load(pathWomen);
        lblWomen = new QLabel(this);
        lblWomen->setGeometry(30, 180, 200, 340);
        lblWomen->setPixmap(pixWomen);
        lblWomen->setVisible(false);

        pixMen.load(pathMen);
        lblMen = new QLabel(this);
        lblMen->setGeometry(30, 180, 200, 340);
        lblMen->setPixmap(pixMen);
        lblMen->setVisible(false);

        lblShopLogo = new QLabel(this);
        pixShopLogo.load(pathShopLogo);
        lblShopLogo->setGeometry(750, 40, 200, 100);
        lblShopLogo->setPixmap(pixShopLogo);

        //Step 0
        gbSellerStep0 = new QGroupBox("Shop assistance->", this);
        gbSellerStep0->setStyleSheet("background-color:pink;");
        gbSellerStep0->setGeometry(530, 90, 200, 100);

        gbCustomerStep0 = new QGroupBox("Enter name", this);
        gbCustomerStep0->setStyleSheet("background-color:pink;");
        gbCustomerStep0->setGeometry(320, 100, 180, 130);

        lblSellerStep0 = new QLabel("Welcome");
        glSellerStep0 = new QGridLayout;
        glSellerStep0->addWidget(lblSellerStep0, 0, 0);
        gbSellerStep0->setLayout(glSellerStep0);
        gbSellerStep0->setVisible(false);

        glCustomerStep0 = new QGridLayout;
        lblCustomerStep0 = new QLabel("Enter your name:");
        glCustomerStep0->addWidget(lblCustomerStep0, 0, 0);
        txtCustomerStep0 = new QTextEdit();
        txtCustomerStep0->setAlignment(Qt::AlignCenter);
        glCustomerStep0->addWidget(txtCustomerStep0, 1, 0);
        pbCustomerStep0 = new QPushButton("-->");
        pbCustomerStep0->setStyleSheet("background-color:pink;");
        glCustomerStep0->addWidget(pbCustomerStep0, 2, 0);
        gbCustomerStep0->setLayout(glCustomerStep0);
        gbCustomerStep0->setVisible(false);

        //Step 1
        gbSellerStep1 = new QGroupBox("Shop assistance->", this);
        gbSellerStep1->setStyleSheet("background-color:pink;");
        gbSellerStep1->setGeometry(530, 90, 200, 100);

        gbCustomerStep1 = new QGroupBox("Please select", this);
        gbCustomerStep1->setStyleSheet("background-color:pink;");
        gbCustomerStep1->setGeometry(320, 100, 180, 130);

        lblSellerStep1 = new QLabel();
        glSellerStep1 = new QGridLayout;
        glSellerStep1->addWidget(lblSellerStep1, 0, 0);
        gbSellerStep1->setLayout(glSellerStep1);
        gbSellerStep1->setVisible(false);

        glCustomerStep1 = new QGridLayout;
        lblCustomerStep1 = new QLabel("1.)Buy\n2.)Sell");
        glCustomerStep1->addWidget(lblCustomerStep1, 0, 0);
        cbCustomerStep1 = new QComboBox();
        cbCustomerStep1->addItem("Select:");
        cbCustomerStep1->addItem("1.)Buy");
        cbCustomerStep1->addItem("2.)Sell");
        glCustomerStep1->addWidget(cbCustomerStep1, 1, 0);
        gbCustomerStep1->setLayout(glCustomerStep1);
        gbCustomerStep1->setVisible(false);

        pbDaily = new QPushButton("DAILY REPORT", this);
        pbDaily->setStyleSheet("Font : 5pt ;background-color:lightblue;");
        pbDaily->setGeometry(780, 344, 80, 20);
        pbDaily->setVisible(true);
        QObject::connect(pbDaily, SIGNAL(clicked()), this, SLOT(dailyToday()));

        //Step 2
        gbSellerStep2 = new QGroupBox("Shop assistance->", this);
        gbSellerStep2->setStyleSheet("background-color:pink;");
        gbSellerStep2->setGeometry(530, 90, 200, 100);

        gbCustomerStep2 = new QGroupBox("Customer", this);
        gbCustomerStep2->setStyleSheet("background-color:pink;");
        gbCustomerStep2->setGeometry(320, 100, 180, 160);

        lblSellerStep2 = new QLabel();
        glSellerStep2 = new QGridLayout;
        glSellerStep2->addWidget(lblSellerStep2, 0, 0);
        gbSellerStep2->setLayout(glSellerStep2);
        gbSellerStep2->setVisible(false);

        glCustomerStep2 = new QGridLayout;
        lblCustomerStep2_1 = new QLabel("Please select currency\n that you want",this);
        glCustomerStep2->addWidget(lblCustomerStep2_1, 0, 0);
        cbCustomerStep2 = new QComboBox(this);
        cbCustomerStep2->addItem("Select:");
        cbCustomerStep2->addItem("1.)USD");
        cbCustomerStep2->addItem("2.)GBP");
        cbCustomerStep2->addItem("3.)EUR");
        cbCustomerStep2->addItem("4.)JPY");
        cbCustomerStep2->addItem("5.)CNY");
        cbCustomerStep2->addItem("6.)SGD");
        cbCustomerStep2->addItem("7.)KRW");
        cbCustomerStep2->addItem("8.)INR");
        cbCustomerStep2->addItem("9.)HKD");
        cbCustomerStep2->addItem("10.)PHP");
        cbCustomerStep2->addItem("11.)IDR");
        cbCustomerStep2->addItem("12.)CHF");
        cbCustomerStep2->addItem("13.)AUD");
        cbCustomerStep2->addItem("14.)NZD");
        cbCustomerStep2->addItem("15.)CAD");
        cbCustomerStep2->addItem("16.)SEK");
        cbCustomerStep2->addItem("17.)DKK");
        cbCustomerStep2->addItem("18.)NOK");

        glCustomerStep2->addWidget(cbCustomerStep2, 18, 0);
        gbCustomerStep2->setLayout(glCustomerStep2);
        gbCustomerStep2->setVisible(false);

        //Step 3
        gbSellerStep3 = new QGroupBox("Shop assistance->", this);
        gbSellerStep3->setStyleSheet("background-color:pink;");
        gbSellerStep3->setGeometry(530, 90, 200, 100);

        gbCustomerStep3 = new QGroupBox("Please input number", this);
        gbCustomerStep3->setStyleSheet("background-color:pink;");
        gbCustomerStep3->setGeometry(320, 100, 180, 130);

        lblSellerStep3 = new QLabel();
        glSellerStep3 = new QGridLayout;
        glSellerStep3->addWidget(lblSellerStep3, 0, 0);
        gbSellerStep3->setLayout(glSellerStep3);
        gbSellerStep3->setVisible(false);

        glCustomerStep3 = new QGridLayout;
        lblCustomerStep3 = new QLabel();
        glCustomerStep3->addWidget(lblCustomerStep3, 0, 0);
        txtCustomerStep3 = new QTextEdit("10");
        txtCustomerStep3->setAlignment(Qt::AlignCenter);
        glCustomerStep3->addWidget(txtCustomerStep3, 1, 0);
        pbCustomerStep3 = new QPushButton("OK");
        glCustomerStep3->addWidget(pbCustomerStep3, 2, 0);
        gbCustomerStep3->setLayout(glCustomerStep3);
        gbCustomerStep3->setVisible(false);

        //Step 4
        gbSellerStep4 = new QGroupBox("Shop assistance->", this);
        gbSellerStep4->setStyleSheet("background-color:pink;");
        gbSellerStep4->setGeometry(530, 90, 200, 100);

        gbCustomerStep4 = new QGroupBox("Please input number", this);
        gbCustomerStep4->setStyleSheet("background-color:pink;");
        gbCustomerStep4->setGeometry(320, 100, 180, 130);

        lblSellerStep4 = new QLabel();
        glSellerStep4 = new QGridLayout;
        glSellerStep4->addWidget(lblSellerStep4, 0, 0);
        gbSellerStep4->setLayout(glSellerStep4);
        gbSellerStep4->setVisible(false);

        glCustomerStep4 = new QGridLayout;
        lblCustomerStep4 = new QLabel();
        glCustomerStep4->addWidget(lblCustomerStep4, 0, 0);
        pbCustomerStep4 = new QPushButton("OK");
        glCustomerStep4->addWidget(pbCustomerStep4, 1, 0);
        gbCustomerStep4->setLayout(glCustomerStep4);
        gbCustomerStep4->setVisible(false);
    }
    void clearSetting() {
        QSettings ("HKEY_CURRENT_USER\\Software\\Organisation",
        QSettings::NativeFormat).remove("");
    }
    void step0() {
        getdata();
        clearSetting();
        declare();
        gbSellerStep1->setVisible(false);
        gbCustomerStep1->setVisible(false);
        gbSellerStep2->setVisible(false);
        gbCustomerStep2->setVisible(false);
        gbSellerStep3->setVisible(false);
        gbCustomerStep3->setVisible(false);
        gbSellerStep4->setVisible(false);
        gbCustomerStep4->setVisible(false);

        gbSellerStep0->setVisible(true);
        gbCustomerStep0->setVisible(true);

        lblSeller->setVisible(true);
        lblShopLogo->setVisible(true);

        QObject::connect(pbCustomerStep0, SIGNAL(clicked()), this, SLOT(select0()));
    }
    void step1() {
        gbSellerStep0->setVisible(false);
        gbCustomerStep0->setVisible(false);
        gbSellerStep2->setVisible(false);
        gbCustomerStep2->setVisible(false);
        gbSellerStep3->setVisible(false);
        gbCustomerStep3->setVisible(false);
        gbSellerStep4->setVisible(false);
        gbCustomerStep4->setVisible(false);

        lblWomen->setGeometry(30, 180, 200, 340);
        lblMen->setGeometry(30, 180, 200, 340);

        cbCustomerStep1->setCurrentIndex(0);
        lblSellerStep1->setText("Hello " + name + "\nMay i help you?");
        srand (time(NULL));
        count = rand() % 2;
        if(count == 0) {
            lblWomen->setVisible(true);
            lblMen->setVisible(false);
        }
        else{
            lblWomen->setVisible(false);
            lblMen->setVisible(true);
        }
        gbSellerStep1->setVisible(true);
        gbCustomerStep1->setVisible(true);

        QMetaObject::invokeMethod(this, "delay", Qt::QueuedConnection, Q_ARG(int, 30), Q_ARG(int, 180));
        QObject::connect(cbCustomerStep1, SIGNAL(currentIndexChanged(int)), this, SLOT(select1(int)));


    }
    void step2(int n) {
        gbSellerStep0->setVisible(false);
        gbCustomerStep0->setVisible(false);
        gbSellerStep1->setVisible(false);
        gbCustomerStep1->setVisible(false);
        gbSellerStep3->setVisible(false);
        gbCustomerStep3->setVisible(false);
        gbSellerStep4->setVisible(false);
        gbCustomerStep4->setVisible(false);

        cbCustomerStep2->setCurrentIndex(0);

        if(n == 1)
            lblSellerStep2->setText("Buy?");
        else
            lblSellerStep2->setText("Sell?");

        gbSellerStep2->setVisible(true);
        gbCustomerStep2->setVisible(true);

        QObject::connect(cbCustomerStep2, SIGNAL(currentIndexChanged(int)), this, SLOT(select2(int)));
    }
    void step3(int n) {
        gbSellerStep0->setVisible(false);
        gbCustomerStep0->setVisible(false);
        gbSellerStep1->setVisible(false);
        gbCustomerStep1->setVisible(false);
        gbSellerStep2->setVisible(false);
        gbCustomerStep2->setVisible(false);
        gbSellerStep4->setVisible(false);
        gbCustomerStep4->setVisible(false);

        if(buyOrSell == 0)
            lblSellerStep3 -> setText("Buy " + sl[n - 1]+"\nRate "+QString::number(buyPrice[n-1])+"\nMax "+QString::number(quantity[n-1]));
        else
           lblSellerStep3 -> setText("Sell " + sl[n - 1]+"\nRate "+QString::number(sellPrice[n-1]));

        lblCustomerStep3->setText(sl[n - 1]);

        txtCustomerStep3->setText("10");
        txtCustomerStep3->setAlignment(Qt::AlignCenter);

        gbSellerStep3->setVisible(true);
        gbCustomerStep3->setVisible(true);

        QObject::connect(pbCustomerStep3, SIGNAL(clicked()), this, SLOT(select3()));
    }
    void step4() {
        gbSellerStep0->setVisible(false);
        gbCustomerStep0->setVisible(false);
        gbSellerStep1->setVisible(false);
        gbCustomerStep1->setVisible(false);
        gbSellerStep2->setVisible(false);
        gbCustomerStep2->setVisible(false);
        gbSellerStep3->setVisible(false);
        gbCustomerStep3->setVisible(false);
        QString ss = "";
        if(buyOrSell == 0)
            ss = ch[0] + " " + sl[currency] + " " + QString::number(buyPrice[currency]) + "*" + QString::number(qty) + "\nTotal " + QString::number(buyPrice[currency] * qty) + " Baht";
        else
            ss = ch[1] + " " + sl[currency] + " " + QString::number(sellPrice[currency]) + "*" + QString::number(qty) + "\nGet " + QString::number(sellPrice[currency] * qty) + " Baht";

        lblSellerStep4->setText(ss);
        lblCustomerStep4->setText("Confirm?");

        gbSellerStep4->setVisible(true);
        gbCustomerStep4->setVisible(true);

        QObject::connect(pbCustomerStep4, SIGNAL(clicked()), this, SLOT(select4()));
    }
    void getdata(){
        quantity.clear();
        buyPrice.clear();
        sellPrice.clear();
        QFile file(pathMoney);
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.errorString();
        }
        else {
            while (!file.atEnd()) {
                QString line = file.readLine();
                QStringList data = line.split(',');
                quantity.append(QString(data.at(0)).toFloat());
                buyPrice.append(QString(data.at(1)).toFloat());
                sellPrice.append(QString(data.at(2)).toFloat());
            }
        }
        file.close();
    }
    void saveData() {
        QFile file(pathMoney);
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << file.errorString();
        }
        else {
            QTextStream stream( &file );
            for(int i = 0; i < quantity.size(); i++) {
                QString data = QString::number(quantity[i]) + "," + QString::number(buyPrice[i]) + "," + QString::number(sellPrice[i]);
                stream << data << Qt::endl;
            }
        }
        file.close();
    }
    void saveDaily() {
        QDate s = QDate::currentDate();
        QTime t = QTime::currentTime();
        QList<int> ttime;
        ttime.append(s.day());
        ttime.append(s.month());
        ttime.append(s.year());
        ttime.append(t.hour());
        ttime.append(t.minute());

        QFile file(pathDaily);
        if (!file.open(QIODevice::Append)) {
            qDebug() << file.errorString();
        }
        else {
            QTextStream stream( &file );
            QString data = QString::number(ttime[0]) + "," +
                           QString::number(ttime[1]) + "," +
                           QString::number(ttime[2]) + "," +
                           QString::number(ttime[3]) + "," +
                           QString::number(ttime[4]) + "," +
                           ch[buyOrSell] + "," +
                           sl[currency] + "," +
                           QString::number(qty) + "," + name;
            stream << data << Qt::endl;
        }
        file.close();
    }
public slots:
    void delay(int n, int m) {
        for(int i = n; i <= m; i += 10) {
            if(count == 0) {
                lblWomen->setGeometry(i, 180, 200, 340);
                lblWomen->repaint();
            }
            else {
                lblMen->setGeometry(i, 180, 200, 340);
                lblMen->repaint();
            }
            QThread::msleep(100);
        }
    }
    void select0(){
        name = txtCustomerStep0->toPlainText();
        if(name.length() > 0) {
            step1();
        }
    }
    void select1(int index){
        if(index == 1 || index ==2){
            buyOrSell = index - 1;
            step2(index);
        }
    }
    void select2(int index){
        if(index >= 1 && index <=18){
            currency = index - 1;//
            step3(index);
        }
    }
    void select3() {
        int count = 0;
        QString s1 = txtCustomerStep3->toPlainText(); //Number to SELL
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] >= '0' && s1[i] <= '9') {
                count++;
            }
        }
        if(count == s1.length()) {
            qty = txtCustomerStep3->toPlainText().toInt();
            if(qty <= quantity[currency]) {
                qDebug() <<qty<<" "<<quantity[currency];
                step4();
            }
        }
        else {
            txtCustomerStep3->setText("10");
            txtCustomerStep3->setAlignment(Qt::AlignCenter);
        }
    }
    void select4() {
        if(buyOrSell == 0) {
            quantity[currency] -= qty;
        }
        else {
            quantity[currency] += qty;
        }
        qDebug() << quantity;
        saveData();
        saveDaily();
        lblWomen->setVisible(false);
        lblMen->setVisible(false);
        step0();
    }
    void dailyToday() {
        QDate s = QDate::currentDate();
        QString daily = "";
        QFile file(pathDaily);
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.errorString();
        }
        else {
            while (!file.atEnd()) {
                QString line = file.readLine();
                QStringList data = line.split(',');
                if(QString(data.at(0)).toInt() == s.day() && QString(data.at(1)).toInt() == s.month() && QString(data.at(2)).toInt() == s.year()) {
                        daily += QStringLiteral("%1").arg(data.at(0).toInt(), 2, 10, QLatin1Char('0')) + "/" +
                                 QStringLiteral("%1").arg(data.at(1).toInt(), 2, 10, QLatin1Char('0')) + "/" +
                                 QStringLiteral("%1").arg(data.at(2).toInt(), 4, 10, QLatin1Char('0')) + " " +
                                 QStringLiteral("%1").arg(data.at(3).toInt(), 2, 10, QLatin1Char('0')) + ":" +
                                 QStringLiteral("%1").arg(data.at(4).toInt(), 2, 10, QLatin1Char('0')) + " ";
                        if(data.at(5) == "Buy")
                            daily += "Buy   ";
                        else
                            daily += "Sell  ";
                        daily += data.at(6) + " "  + QStringLiteral("%1").arg(data.at(7).toInt(), 4, 10, QLatin1Char(' ')) + " " +
                                 data.at(8);
                }
            }
        }
        file.close();

        QFile file1(pathDailyToday);
        if (!file1.open(QIODevice::WriteOnly)) {
            qDebug() << file1.errorString();
        }
        else {
            QTextStream stream( &file1 );
            stream << daily << Qt::endl;
        }
        file1.close();
        qDebug() << daily;
        QDesktopServices::openUrl(QUrl::fromLocalFile(pathDailyToday));
    }
};
#endif // MAIN_H
