#ifndef CONTACT_H
#define CONTACT_H

#include "numero.h"
#include <vector>
#include <iostream>

using namespace std;


class Contact
{
public:
    Contact();
    Contact(string nom,string prenom,string email,Numero tel);
    string getNom();
    string getprenom();
    string getemail();
    vector<Numero> getTel();
    void setNom(string);
    void setprenom(string);
    void setemail(string);
    void ajout(Numero tel);
    virtual ~Contact();
private:
    string _nom;
    string _prenom;
    string _email;
    vector<Numero> _tel;
};

#endif // CONTACT_H
