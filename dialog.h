#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QRandomGenerator>
#include <QMessageBox>

#include "positiondialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

public slots:
    void closed();

signals:
    void triggered(double lat, double lon);

private slots:
    void on_btnOpen_clicked();
    void on_btnClose_clicked();
    void timeout();

private:
    Ui::Dialog *ui;
    QTimer timer;
    PositionDialog *dlg;
};
#endif // DIALOG_H
