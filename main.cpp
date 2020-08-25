#include "dialog.h"

#include <QApplication>

/*
 What
 Use Qtconcurrent to get a value

 Description
 I dont care just make threading easy!!!

 Why
 Threading is overly complex, but concurrent makes it easy

 Example
 use QFuture Watcher to get a value
 QT += concurrent
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return a.exec();
}
