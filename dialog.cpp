#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(&timer,&QTimer::timeout,this, &Dialog::timeout);

    timer.setInterval(1000);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::closed()
{
    timer.stop();
    QMessageBox::information(this,"Closed","The dialog was closed, stopping timer");
}


void Dialog::on_btnOpen_clicked()
{
    dlg = new PositionDialog(this);
    connect(dlg,&PositionDialog::closed,this, &Dialog::closed);
    connect(this,&Dialog::triggered,dlg,&PositionDialog::triggered);

    dlg->show();
    timeout();
    timer.start();
}

void Dialog::on_btnClose_clicked()
{
    if(dlg){
        timer.stop();
        dlg->close();
        dlg->deleteLater();
    }
}

void Dialog::timeout()
{
    double high = 90.00;
    double lat = QRandomGenerator::global()->bounded(high);
    double lon = QRandomGenerator::global()->bounded(high);

    emit triggered(lat,lon);
}
