#include <QApplication>
#include "Title.h"

int main (int argc, char* argv[]) {
  QApplication appl(argc, argv);
  Title title;
  title.show();
  return appl.exec();
}
