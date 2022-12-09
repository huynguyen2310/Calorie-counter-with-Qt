#include "personn.h"

Personn::Personn(QObject *parent)
    : QObject{parent}
{

}

void Personn::setWeight(double weight)
{
    if(m_weight!=weight){
        m_weight = weight;
//        emit weightChange();
    }
}
