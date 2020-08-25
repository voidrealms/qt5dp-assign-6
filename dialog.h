#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFuture>
#include <QFutureWatcher>
#include <QtConcurrent>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int getNumber(int max);

private slots:
    void finished();
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QFuture<int> m_future;
    QFutureWatcher<int> m_watcher;
};
#endif // DIALOG_H
