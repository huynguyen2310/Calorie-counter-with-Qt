#include "widget.h"
#include "./ui_widget.h"
#include <QMessageBox>
#include <QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_person.setWeight(ui->weightSpinBox->value());
    m_time = ui->timeSpinBox->value();
    m_speed = ui->speedSpinBox->value();

    connect(ui->weightSpinBox, &QDoubleSpinBox::valueChanged,this,&Widget::weight_changed);
    connect(ui->timeSpinBox, &QDoubleSpinBox::valueChanged, this, &Widget::time_changed);
    connect(ui->speedSpinBox, &QDoubleSpinBox::valueChanged, this, &Widget::speed_changed);
    connect(ui->quitButton,&QPushButton::clicked, [=](){
        int ret = QMessageBox::information(this,"Message Title", "Something happend. Do you want to do something?", QMessageBox::Ok | QMessageBox::Cancel);
        if(ret == QMessageBox::Ok)  {
            qDebug()<<"You clicked OK!!";
            QTimer::singleShot(5000, this,&Widget::quitApp);
        }
        else if (ret == QMessageBox::Cancel) qDebug()<<"You clicked Cancel!!";

    });
    connect(ui->saveButton,&QPushButton::clicked, [=](){
        int retSave = QMessageBox::information(this,"Message Title", "Do you want to save your information?", QMessageBox::Ok | QMessageBox::Cancel);
        if(retSave == QMessageBox::Ok)  qDebug()<<"You saved!!";
        else if (retSave == QMessageBox::Cancel) qDebug()<<"You didnt save!!";

    });
    connect(this, &Widget::calory_count_changed,[=](){
        ui->countLabel->setText(QString::number(m_calory_count));
    });
//    connect(this,&Widget::calory_count_changed, ui->countLabel, &QLabel::setText);
//    ui->countLabel->setText(QString::number(m_calory_count));
    calculate_cal();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::calculate_cal()
{
    m_calory_count = ((0.0215*(m_speed*m_speed*m_speed))-(0.1765*(m_speed*m_speed))
                      +(0.8710*m_speed)+1.4577)*m_person.weight()*m_time;
    emit calory_count_changed();
}

void Widget::weight_changed(double weight)
{
    m_person.setWeight(weight);
    calculate_cal();
}

void Widget::time_changed(double time)
{
    m_time = time;
    calculate_cal();
}

void Widget::speed_changed(double speed)
{
    m_speed = speed;
    calculate_cal();
}

void Widget::quitApp()
{
    QApplication::quit();
}



