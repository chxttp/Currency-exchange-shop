#ifndef WIDGET2_H
#define WIDGET2_H

#include <QMainWindow>
#include <QCoreApplication>
#include <QFile>
#include <QStringList>
#include <QDebug>

class Widget2 : public QMainWindow {
    Q_OBJECT
public:
  Widget2(QWidget *parent = NULL) : QMainWindow(parent) {
    this->resize(500, 400);
    this->setWindowTitle("Game");
      QStringList wordList;
      QList<float> qty;
      QList<float> buy;
      QList<float> sell;
      QString path1 = QCoreApplication::applicationDirPath() + "/money.csv";
      QFile file(path1);
      if (!file.open(QIODevice::ReadOnly)) {
          qDebug() << file.errorString();
      }
      else {

          while (!file.atEnd()) {
              QString line = file.readLine();
              QStringList data = line.split(',');
              qty.append(QString(data.at(0)).toFloat());
              buy.append(QString(data.at(1)).toFloat());
              sell.append(QString(data.at(2)).toFloat());
          }
          qDebug() << qty;
          qDebug()<<buy;
          qDebug()<<sell;
      }
      file.close();

//      QString path2 = QCoreApplication::applicationDirPath() + "/abcd.csv";
//      QFile file1(path2);
//      if (!file1.open(QIODevice::WriteOnly)) {
//          qDebug() << file.errorString();
//      }
//      else {
//          QTextStream stream( &file1 );
//          for(int i = 0; i < data.size(); i++) {
//              stream << QString::number(data[i]) << "," << endl;
//          }
//      }
//      file1.close();
  }
};
#endif // WIDGET2_H
