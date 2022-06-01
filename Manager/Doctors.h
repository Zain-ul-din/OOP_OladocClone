//
//
//

#ifndef DOCTORS_H
#define DOCTORS_H

#include "./Users.h"
#include "../Users/Doctor.h"

#define MAX 100000

class Doctors;

class Doctors : public Users {
public:
    Doctors();

    /* OverRides */

    void SignUp() override;
    void SignIn() override;

    void Delete(string options = "") override;
    void Update(string options = "") override;

    void LoadData() override;
    void SaveData() override;

private:
    Doctor** doctors = NULL;
    static const string DOCTORS_FILEPATH;
    // Helpers
    void Init ();

    bool SignUp_Helper (Doctor** doctor);  // returns => sign up succeed
    bool IsConatins (Doctor& doctor); // returns => doctor exists in record

};

const string Doctors::DOCTORS_FILEPATH = "DOCTORS_DATA.text";

Doctors::Doctors() { this->Init(); }

void Doctors::SignUp() {
     Doctor* doctor = new Doctor();
     if (!SignUp_Helper(&(doctor))) return; // input Handler
     this->idx += 1;
     this->doctors[idx] = doctor;
     this->SaveData();
}

void Doctors::SignIn() {

}



void Doctors::LoadData() {
    ifstream in;
    in.open(DOCTORS_FILEPATH , ios::in);
    if (in.fail() || IsEmptyFile(in)) {
        this->SaveData();
        in.close();
        return;
    }

    in.close();
}

void Doctors::SaveData() {
    ofstream out;
    out.open(DOCTORS_FILEPATH , ios::out);
    if (out.fail() || this->doctors[0] == NULL) {
        out.close();
        return ;
    }

}

void Doctors::Delete(string options ) {

}

void Doctors::Update(string options ) {

}

/*  Helpers */

void Doctors::Init() {
    this->doctors = new Doctor*[MAX];
    for (int i = 0 ; i < MAX ; i += 1) this->doctors[i] = NULL;
    this->LoadData();
}

bool Doctors::SignUp_Helper(Doctor **doctor) {

    string email = GetString(">> Enter Email Address : ");
    string cnicNumber = GetString(">> Enter Cnic Number : ");
    (*doctor)->setEmail(email);
    (*doctor)->setCnicNumber(cnicNumber);

    // Duplicate Check
    if (this->IsConatins(**doctor))
        return false;

    return true;
}

bool Doctors::IsConatins(Doctor &doctor) {
    int idx = 0;
    while (this->doctors != NULL) {
        if (*(this->doctors[idx]) == doctor) return true;
        idx += 1;
    }
    return false;
}

#endif //DOCTORS_H
