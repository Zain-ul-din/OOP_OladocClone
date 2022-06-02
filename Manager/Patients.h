//
// Created by 97152 on 02/06/2022.
//

#ifndef PAIDPROJECT_PATIENTS_H
#define PAIDPROJECT_PATIENTS_H


#include "./Users.h"

class Patients  : Users{
public:
    void SignUp() override;
    void SignIn() override;
    void Delete(string options) override;
    void Update(string options) override;
    void LoadData() override;
    void SaveData() override;

    Patients** patients = NULL;
    int currentLoggedInPatientIdx;
private:
    static const string PATIENTS_FILEPATH;
};

const string Patients::PATIENTS_FILEPATH = "PATIENTS_DATA.text";

void Patients::SignUp() {

}

void Patients::SignIn() {

}

void Patients::Delete(string options) {

}

void Patients::Update(string options) {

}

void Patients::LoadData() {

}

void Patients::SaveData() {

}

#endif //PAIDPROJECT_PATIENTS_H
