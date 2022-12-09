#ifndef PERSONN_H
#define PERSONN_H

#include <QObject>
#include <QWidget>

class Personn : public QObject
{
    Q_OBJECT
public:
    explicit Personn(QObject *parent = nullptr);
    double weight() const{return m_weight;}
    void setWeight(double weight);

signals:
    void weightChange();
private:
    double m_weight = 0.0;

};

#endif // PERSONN_H
