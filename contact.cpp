#include "contact.h"
#include "numero.h"
#include <vector>
#include <iostream>

using namespace std;


Contact::Contact()
{

}

Contact::~Contact()
{
    //dtor
}
Contact::Contact(string nom, string prenom, string email, Numero tel)
{
    this->_nom = nom;
    this->_prenom = prenom;
    this->_email = email;
    this->_tel.push_back(tel);
}

string Contact::getNom()
{
    return this->_nom;
}

string Contact::getprenom()
{
    return this->_prenom;
}

string Contact::getemail()
{
    return this->_email;
}

void Contact::setNom(string nom)
{
    this->_nom = nom;
}

void Contact::setprenom(string prenom)
{
    this->_prenom = prenom;
}
vector<Numero> Contact::getTel()
{
    return this->_tel;
}

void Contact::setemail(string email)
{
    this->_email = email;
}

void Contact::ajout(Numero tel)
{
    int n=0;
    vector<Numero>::iterator it;
    for( it = _tel.begin() ; it != _tel.end() ; it++ )n++;
    if(n<4)
    {
       this->_tel.push_back(tel);
    }
    else
    {
        cout << "vous avez deja plu de 3 numero dans ce contac";
    }
}
