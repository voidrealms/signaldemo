#include "positiondialog.h"
#include "ui_positiondialog.h"

PositionDialog::PositionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PositionDialog)
{
    ui->setupUi(this);
}

PositionDialog::~PositionDialog()
{
    delete ui;
}

void PositionDialog::triggered(double lat, double lon)
{
    ui->txtlat->setText(QString::number(lat));
    ui->txtlon->setText(QString::number(lon));
}

void PositionDialog::on_buttonBox_accepted()
{
    emit closed();
    accept();
}
