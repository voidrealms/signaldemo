#ifndef POSITIONDIALOG_H
#define POSITIONDIALOG_H

#include <QDialog>


namespace Ui {
class PositionDialog;
}

class PositionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PositionDialog(QWidget *parent = nullptr);
    ~PositionDialog();

signals:
    void closed();

public slots:
    void triggered(double lat, double lon);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::PositionDialog *ui;
};

#endif // POSITIONDIALOG_H
