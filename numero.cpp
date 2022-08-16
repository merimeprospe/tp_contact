#include "numero.h"

Numero::Numero()
{

}
Numero::~Numero()
{
    //dtor
}
Numero::Numero(long int tel)
{
    this->_tel = tel;
}

long int Numero::getTel()
{
    return this->_tel;
}

void Numero::setTel(long int tel)
{
    this->_tel = tel;
}
