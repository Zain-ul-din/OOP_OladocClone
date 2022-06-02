//
// Created by 97152 on 02/06/2022.
//

#ifndef PATIENT_H
#define PATIENT_H

#include "./User.h"

class Patient : public User {
public:

    /* Constructor */
    Patient();
    Patient(const string &name , const string &cnicNumber , const string &password , int contactNumber , double balance , int age);

    /* Getter Setter */
    double getBalance() const;
    void setBalance(double balance) ;
    int getAge() const ;
    void setAge(int age);
    int getContactNumber() const;
    void setContactNumber(int contactNumber);

    /* Over Rides */
    void Update() override ;

    /* Methods */
    void ReChargeBalance ();

    /* Operator OverLoading */
    friend ostream &operator<<(ostream &os, const Patient &patient);
    friend ofstream &operator << (ofstream &outFile , const Patient& patient);
private:
    int contactNumber;
    double balance;
    int age;
};

/* Constructor */

Patient::Patient() {
    this->balance = 3500;
    this->age = 18;
}

Patient::Patient(const string &name, const string &cnicNumber, const string &password, int contactNumber,
double balance, int age) : User(name, cnicNumber, password), contactNumber(contactNumber),
balance(balance), age(age) {}

/* Getter Setter */
double Patient::getBalance() const { return balance;}
void Patient::setBalance(double balance) { this->balance = balance;}
int Patient::getAge() const { return age;}
void Patient::setAge(int age) { this->age = age;}
int Patient::getContactNumber() const { return contactNumber;}
void Patient::setContactNumber(int contactNumber) { this->contactNumber = contactNumber;}

/* Over Rides */
void Patient::Update() { }

/* Methods */
void Patient::ReChargeBalance() { }

/* Operator OverLoading */
ostream &operator<<(ostream &os, const Patient &patient) {

    return os;
}

ofstream &operator << (ofstream &outFile , const Patient& patient) {
    outFile << patient.name << reserveSeparator
    << patient.cnicNumber << reserveSeparator
    << patient.password << reserveSeparator
    << patient.age << reserveSeparator
    << patient.balance << reserveSeparator
    << patient.contactNumber << "\n";
}

#endif //PATIENT_H
