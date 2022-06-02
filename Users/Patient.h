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

    static Patient* StrToObj (string&);
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
void Patient::Update() {
      cout << "\n -- Update Menu \n";
      cout << "  - Edit Contact Number - 1 \n";
      cout << "  - Edit age            - 2 \n";
      cout << "  - Exit                - 3 \n";
      int choice = GetInput<int>(" Enter Choice _ ");
      switch (choice)
    {
        case 1:
            this->contactNumber = GetInput<int>(" Enter new Contact Number : ");
            break;
        case 2:
            this->age = GetInput<int>("Enter correct age : ");
            break;
        default:
            cout << " -- Never Mind \n";
    }
}

/* Methods */
void Patient::ReChargeBalance() { }

/* Operator OverLoading */
ostream &operator<<(ostream &os, const Patient &patient) {

    return os;
}

// File Write
ofstream &operator << (ofstream &outFile , const Patient& patient) {
    outFile << patient.name << reserveSeparator
    << patient.cnicNumber << reserveSeparator
    << patient.password << reserveSeparator
    << patient.age << reserveSeparator
    << patient.balance << reserveSeparator
    << patient.contactNumber << "\n";
    return outFile;
}

// File Read
Patient *Patient::StrToObj(string &str) {
    string aux [6];
    int idx  = 0 ;
    for (int i = 0 ; i < 6 ; i += 1)
        if (str[i] == reserveSeparator) idx += 1;
        else aux[idx].push_back(str[i]);

    Patient* patient = new Patient();
    patient->name = Replace(aux[0] , '_' , ' ');
    patient->cnicNumber = aux[1];
    patient->password = aux[2];
    patient->age = stoi(aux[3]);
    patient->balance = stod(aux[4]);
    patient->contactNumber = stoi(aux[5]);
    return patient;
}


#endif //PATIENT_H
