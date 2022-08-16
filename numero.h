#ifndef NUMERO_H
#define NUMERO_H


class Numero
{
public:
    Numero();
    Numero(long int);
    long int getTel();
    void setTel(long int);
    virtual ~Numero();

private:
    long int _tel;

};

#endif // NUMERO_H
