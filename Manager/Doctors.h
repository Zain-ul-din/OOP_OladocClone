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

    int currentLoggedInDoctorIdx;
    Doctor** doctors = NULL;

private:
    static const string DOCTORS_FILEPATH;
    // Helpers
    void Init ();

    bool SignUp_Helper (Doctor** doctor);  // returns => sign up succeed
    bool IsConatins (Doctor& doctor); // returns => doctor exists in record
    bool CheckPassword (Doctor& doctor); // password checker
    int  GetIdxOf (Doctor& doctor); // returns => Idx of doctor in record
};

const string Doctors::DOCTORS_FILEPATH = "DOCTORS_DATA.text";

Doctors::Doctors() { this->Init(); }

void Doctors::SignUp() {
     Doctor* doctor = new Doctor();
     if (!SignUp_Helper(&doctor)) return; // input Handler
     this->idx += 1;
     this->doctors[idx] = doctor;
     this->SaveData();
}

void Doctors::SignIn() {
     Doctor* doctor = new Doctor ();
     string userName = GetString(" >> Enter User Name : ");
     if(!IsConatins(*doctor)) return;
     string password = GetString(" >> Enter Password : ");
     // Password Check
     if (!CheckPassword(*doctor)) return;
     this->currentLoggedInDoctorIdx = GetIdxOf(*doctor);
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
    currentLoggedInDoctorIdx = -1;
    this->doctors = new Doctor*[MAX];
    for (int i = 0 ; i < MAX ; i += 1) this->doctors[i] = NULL;
    this->LoadData();
}

bool Doctors::SignUp_Helper(Doctor **doctor) {

    string email = GetString(" >> Enter Email Address : ");
    string cnicNumber = GetString(" >> Enter Cnic Number : ");
    (*doctor)->setEmail(email);
    (*doctor)->setCnicNumber(cnicNumber);

    // Duplicate Check
    if (this->IsConatins(**doctor)) {
        PrintError("Account already exists please use signIn instead");
        return false;
    }

    // sign Up Logic
    string password = GetString(" >> Enter password : ");
    string passwordCheck = "";

    // Verify Password
    do {
        passwordCheck = GetString(" >> Retype password : ");
        if (passwordCheck != password) PrintError("2nd password is not matching with 1st one please retype again");
    } while (passwordCheck != password);


    /*
     * string email;
    int experienceYears;
    string hospitalName   , city;
    string specializationArea;
    int startingHour , endingHours ; // 24 hours clock format
    double rates , onLineRates; // appointment rates
     */
    return true;
}

bool Doctors::IsConatins(Doctor &doctor) {
    int idx = 0;
    while (this->doctors[idx] != NULL) {
        if (*(this->doctors[idx]) == doctor) return true;
        idx += 1;
    }
    return false;
}

bool Doctors::CheckPassword(Doctor &doctor) {
    int idx = 0 ;
    while (this->doctors[idx] != NULL) {
        Doctor* _doctor = this->doctors[idx];
        if( _doctor->getPassword() == doctor.getPassword() && _doctor->getPassword()) return true;
        idx += 1;
    }
    return false;
}

int Doctors::GetIdxOf(Doctor &doctor) {
    int idx = 0 ;
    while (this->doctors[idx] != NULL) {
        if (doctor == *(this->doctors[idx]))
            return idx;
        idx += 1;
    }
    return -1;
}

#endif //DOCTORS_H
