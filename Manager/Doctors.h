//
//
//

#ifndef DOCTORS_H
#define DOCTORS_H

#include "./Users.h"

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
    bool FindsDoctorUserName (string& name); // returns => doctor name in record
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

    string email = ""  , cnicNumber = "";
    bool emailValidator = false;
    bool cnicValidator = false;

    do {
        email = GetString(" >> Enter Email Address : ");
        emailValidator = ValidateEmail(email , "@gmail.com");
        if (!emailValidator) PrintError("Invalid email address please enter correct one ");
    } while (!emailValidator);

    do {
        cnicNumber = GetString(" >> Enter Cnic Number : ");
        cnicValidator = ValidateCnic(cnicNumber);
        if (!cnicValidator)
            PrintError("Invalid Cnic Number ! cnic should be 13 digits ");
    } while (!cnicValidator);

    (*doctor)->setEmail(email);
    (*doctor)->setCnicNumber(cnicNumber);

    // Duplicate Check
    if (this->IsConatins(**doctor)) {
        PrintError("Account already exists please use signIn instead");
        return false;
    }

    // sign Up Logic
    string password = "" , passwordCheck = "" , name = "";
    bool isNameAleadyTaken = false;

    do {
        name = GetString(" >> Enter user name _ ");
        isNameAleadyTaken = FindsDoctorUserName(name);
        if (isNameAleadyTaken)
            cout << " Name Already Taken please use new name ";
    } while (isNameAleadyTaken);

    // Verify's Password
    do {
        bool passwordValidator = false;
        do {
            password = GetString(" >> Enter password ( Password must be 8 characters long and the use of a minimum of one special character , uppercase , lowercase , and the numeric digit is a must ) : ");
            passwordValidator = ValidatePassword(password , 8);
            if(!passwordValidator)
                PrintError("Invalid Password");
        } while (!passwordValidator);
        passwordCheck = GetString(" >> Retype password : ");
        if (passwordCheck != password) PrintError("2nd password is not matching with 1st one please retype again");
    } while (passwordCheck != password);

    (*doctor)->setPassword(password);

    // gets doctor associated data

    cout << "\n -- You're almost done with registration please provide some information about you :-) \n";

    string  specializationArea = "";
    do {
        cout << "\n -- Select You're specialization area\n";
        for (int  i = 0 ; i < 4; i  += 1)
            cout << " - " << Doctor::SpecializationList[i] << " - " << i <<"\n";
        int choice = GetInt("\n >> Enter you're selection _  ");
        specializationArea = Doctor::GetSpecializationByIdx(choice);
        if (specializationArea == "NULL")
            PrintError("Invalid Choice");
        else cout << "\n You Select _ " << specializationArea << "\n";
    } while (specializationArea == "NULL");

    int experienceYears = GetInt(" >> How many years of experience you have _ ");
    string hospitalName  = GetString(" >> Enter you're hospital name _ ") , city = GetString(" >> Enter city name _ ");
    int startingHour = GetInt(" >> Enter appointments starting Time WRT => 24 Hour format _  "), endingHours = GetInt(" >> Enter appointments ending Time WRT => 24 Hour format _  ") ;
    double rates  = GetDouble(" >> Enter in person appointment rate _ ") , onLineRates = GetDouble(" >> Enter online appointment rate _ ");

    (*doctor)->setSpecializationArea(specializationArea);
    (*doctor)->setExperienceYears(experienceYears);
    (*doctor)->setHospitalName(hospitalName);
    (*doctor)->setStartingHour(startingHour);
    (*doctor)->setEndingHours(endingHours);
    (*doctor)->setRates(rates);
    (*doctor)->setOnLineRates(onLineRates);

    cout << "\n -- Regeneration Succeed :-) ";
    cout << "\n -- Please use this userName and password to login";
    cout << "\n -- User Name : " << (*doctor)->getName() ;
    cout << "\n -- Password  : " << (*doctor)->getPassword() << "\n";

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
        if( _doctor->getPassword() == doctor.getPassword() && doctor.getName() == _doctor->getName()) return true;
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

bool Doctors::FindsDoctorUserName(string &name) {
    int idx = 0;
    while (this->doctors[idx] != NULL) {
        if (name == this->doctors[idx]->getName())
            return true;
    }
    return false;
}

#endif //DOCTORS_H
