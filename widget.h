#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "personn.h"
#include <QPushButton>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

 private slots:
    void calculate_cal();
    void weight_changed(double weight);
    void time_changed(double time);
    void speed_changed(double speed);
    void quitApp();
    void on_quitButton_clicked();

signals:
    void calory_count_changed();

private:
    Ui::Widget *ui;
    Personn m_person;
    double m_time;
    double m_speed;
    double m_calory_count;
};
#endif // WIDGET_H
