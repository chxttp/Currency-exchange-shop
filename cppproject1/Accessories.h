#ifndef ACCESSORIES_H
#define ACCESSORIES_H

#include <QLabel>
#include <QMainWindow>
#include <QAction>
#include <QPushButton>
#include <QCoreApplication>
#include <QTextEdit>
#include <QComboBox>
#include <QGroupBox>
#include <QGridLayout>

class Accessories {
public:
    //Data
    QString pathMoney = QCoreApplication::applicationDirPath() + "/money.csv";
    QString pathDaily = QCoreApplication::applicationDirPath() + "/daily.csv";
    QString pathDailyToday = QCoreApplication::applicationDirPath() + "/dailyToday.txt";

    //General
    int buyOrSell, currency, count, qty;
    QString name;
    QStringList sl{"USD", "GBP", "EUR" ,"JPY","CNY","SGD","KRW","INR","HKD","PHP","IDR","CHF","AUD","NZD","CAD","SEK","DKK","NOK"}, ch{"Buy", "Sell"};
    QList<float> quantity, buyPrice, sellPrice;

    //Title.h
    QString pathLogo = QCoreApplication::applicationDirPath() + "/pic/logo.jpg";
    QPixmap pixLogo;
    QLabel *lblLogo;
    QPushButton *pbLogo;

    //Main.h --> Charactor
    QString pathSeller = QCoreApplication::applicationDirPath() + "/pic/pic1.jpg";
    QString pathWomen = QCoreApplication::applicationDirPath() + "/pic/pic2.jpg";
    QString pathMen = QCoreApplication::applicationDirPath() + "/pic/pic3.jpg";
    QString pathShopLogo = QCoreApplication::applicationDirPath() + "/pic/welcome2.gif";
    QPixmap pixSeller, pixWomen, pixMen, pixShopLogo;
    QLabel *lblSeller, *lblWomen, *lblMen, *lblShopLogo;
    QPushButton *pbDaily;

    //Main.h --> Step0 --> Enter name
    QGroupBox *gbSellerStep0, *gbCustomerStep0;
    QGridLayout *glSellerStep0,*glCustomerStep0;
    QLabel *lblSellerStep0, *lblCustomerStep0;
    QTextEdit *txtCustomerStep0;
    QPushButton *pbCustomerStep0;

    //Main.h --> Step1 --> Ask Buy / Sell
    QGroupBox *gbSellerStep1, *gbCustomerStep1;
    QGridLayout *glSellerStep1,*glCustomerStep1;
    QLabel *lblSellerStep1, *lblCustomerStep1;
    QComboBox *cbCustomerStep1;

    //Main.h --> Step2 --> Ask Currency
    QGroupBox *gbSellerStep2, *gbCustomerStep2;
    QGridLayout *glSellerStep2,*glCustomerStep2;
    QLabel *lblSellerStep2, *lblCustomerStep2_1;
    QComboBox *cbCustomerStep2;

    //Main.h --> Step3 --> Ask Qty
    QGroupBox *gbSellerStep3, *gbCustomerStep3;
    QGridLayout *glSellerStep3,*glCustomerStep3;
    QLabel *lblSellerStep3, *lblCustomerStep3;
    QTextEdit *txtCustomerStep3;
    QPushButton *pbCustomerStep3;

    //Main.h --> Step4 --> Confirm
    QGroupBox *gbSellerStep4, *gbCustomerStep4;
    QGridLayout *glSellerStep4,*glCustomerStep4;
    QLabel *lblSellerStep4, *lblCustomerStep4;
    QPushButton *pbCustomerStep4;
};
#endif // ACCESSORIES_H
