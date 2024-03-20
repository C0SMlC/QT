#ifndef PERSONCLASS_H
#define PERSONCLASS_H

#include <bits/stdc++.h>
using namespace std;

class Person
{
private:
    string name;
    string email;
    string password;
    string confirmPassword;



public:
    Person(string name,string email, string password, string confirmPassword);
    void friend handleSubmit();
};

#endif // PERSONCLASS_H
