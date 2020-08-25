#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(&m_watcher, &QFutureWatcher<int>::finished,this, &Dialog::finished);
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::getNumber(int max)
{
    QThread::currentThread()->msleep(5000);
    return QRandomGenerator::global()->bounded(max);
}

void Dialog::finished()
{
    ui->label->setText(QString::number(m_future.result()));
}

void Dialog::on_pushButton_clicked()
{

    m_future = QtConcurrent::run(this,&Dialog::getNumber, 4000);
    m_watcher.setFuture(m_future);
}
