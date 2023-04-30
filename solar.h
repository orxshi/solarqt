#ifndef SOLAR_H
#define SOLAR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Solar; }
QT_END_NAMESPACE

class Solar : public QMainWindow
{
    Q_OBJECT

public:
    Solar(QWidget *parent = nullptr);
    ~Solar();

private slots:
    void on_pb_tilt_clicked();
    void draw_tilt_insolation();

    void setProgress(int progress);


    void on_pb_di_clicked();

    void on_dsb_io_valueChanged(double arg1);

private:
    Ui::Solar *ui;
};
#endif // SOLAR_H
