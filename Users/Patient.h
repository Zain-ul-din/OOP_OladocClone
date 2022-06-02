//
// Created by 97152 on 02/06/2022.
//

#ifndef PATIENT_H
#define PATIENT_H

#include <ostream>
#include "./User.h"

class Patient : public User {
public:

    Patient();
    Patient(const string &name, const string &cnicNumber, const string &password, double balance, int age);

    double getBalance() const;
    void setBalance(double balance) ;
    int getAge() const ;
    void setAge(int age);

    void Update() override ;

    void ReChargeBalance ();

    friend ostream &operator<<(ostream &os, const Patient &patient);
    friend ofstream &operator << (ofstream &outFile , const Patient& patient);

private:
    double balance;
    int age;
};

Patient::Patient() {
    this->balance = 3500;
    this->age = 18;
}

Patient::Patient(const string &name, const string &cnicNumber, const string &password, double balance, int age) :
User(name , cnicNumber , password ) ,balance(balance),age(age) {}

double Patient::getBalance() const { return balance;}
void Patient::setBalance(double balance) { this->balance = balance;}
int Patient::getAge() const { return age;}
void Patient::setAge(int age) { this->age = age;}

void Patient::Update() { }

ostream &operator<<(ostream &os, const Patient &patient) {

    return os;
}

ofstream &operator << (ofstream &outFile , const Patient& patient) {
    outFile << patient.name << reserveSeparator
    << patient.cnicNumber << reserveSeparator
    << patient.password << reserveSeparator
    << patient.age << reserveSeparator
    << patient.
}

#endif //PATIENT_H
