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

    void LoadData() override;
    void SaveData() override;

    void Update(string options = "") override;

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

    int FindDoctorByUserName (string& name); // returns => doctor name in record
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
     string userName = GetString("Enter User Name : ");
     doctor->setName(userName);
         if(!IsConatins(*doctor))
     {
         PrintError("User don't exists please use sign up instead !");
         return;
     }
        int attempts = 0;
        for ( ; attempts < 3 ; attempts += 1)
     {
         string password = GetString("Enter Password : ");
         doctor->setPassword(password);
         if (CheckPassword(*doctor)) break;
         PrintError("Wrong password Please type correct password !");
     }

     if (attempts >= 3) PrintError("Some thing went wrong Login Fail");

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

    string aux;
    while (getline(in , aux , '\n')){
        idx += 1;
        this->doctors[idx] = Doctor::StrToObj(aux);
    }
    in.close();
}

void Doctors::SaveData() {
    ofstream out;
    out.open(DOCTORS_FILEPATH , ios::out);

    if (out.fail()) {
        out.close();
        return ;
    }

    for (int  i = 0 ; i < MAX && this->doctors[i] != NULL ; i += 1)
        out << *(this->doctors[i]);
    out.close();
}

void Doctors::Delete(string options ) {

}



/*  Helpers */

void Doctors::Init() {
    idx = -1;
    currentLoggedInDoctorIdx = -1;
    this->doctors = new Doctor*[MAX];
    for (int i = 0 ; i < MAX ; i += 1) this->doctors[i] = NULL;
    this->LoadData();
}

bool Doctors::SignUp_Helper(Doctor **doctor) {

    string email = GetEmail("Enter Email Address : ")
    , cnicNumber= GetCnic("Enter Cnic Number : ");
    (*doctor)->setEmail(email);
    (*doctor)->setCnicNumber(cnicNumber);

    // Duplicate Check
    if (this->IsConatins(**doctor)) {
        PrintError("Account already exists please use signIn instead");
        return false;
    }

    // sign Up Logic
    string password = GetPassword
    ("Enter password ( Password must be 8 characters , have one special character , uppercase , lowercase , and the numeric digit ) : ") ,   name;
    (*doctor)->setPassword(password);

    bool isNameAlreadyTaken = false;
        do
    {
        name = GetString("Enter user name _ ");
        isNameAlreadyTaken = FindDoctorByUserName(name) != -1;
        if (isNameAlreadyTaken) PrintError("Name Already Taken please use new name ");
    }
        while (isNameAlreadyTaken);

    // gets doctor associated data
    cout << "\n -- You're almost done with registration please provide some information about you :-) \n";

    (*doctor)->InputSpecializationArea();
    (*doctor)->InputAvailableDays();

    int experienceYears = Clamp(GetInput<int>("How many years of experience you have _ ") , 0 , 100);
    string hospitalName  = GetString("Enter you're hospital name _ ")
    , city = GetString("Enter city name _ ");
    (*doctor)->InputAppointmentsTime();
    double rates  = abs(GetInput<double>("Enter in person appointment rate _ "))
    , onLineRates = abs(GetInput<double>("Enter online appointment rate _ "));

    (*doctor)->setName(name);
    (*doctor)->setExperienceYears(experienceYears);
    (*doctor)->setCity(city);
    (*doctor)->setHospitalName(hospitalName);
    (*doctor)->setRates(rates);
    (*doctor)->setOnLineRates(onLineRates);

    cout << "\n -- Registration Succeed :-) ";
    cout << "\n -- Please use this userName and password to login";
    cout << "\n -- User Name : " << (*doctor)->getName() ;
    cout << "\n -- Password  : " << (*doctor)->getPassword() << "\n";

    return true;
}

bool Doctors::IsConatins(Doctor &doctor) {
    for (int i = 0 ; i < MAX && this->doctors[i] != NULL ; i += 1 )
        if (*(this->doctors[i]) == doctor) return true;
    return false;
}

bool Doctors::CheckPassword(Doctor &doctor) {
    for (int  i = 0 ; i < MAX && this->doctors[i] != NULL ; i += 1){
        Doctor* _doctor = this->doctors[i];
        if( _doctor->getPassword() == doctor.getPassword() && doctor.getName() == _doctor->getName())
            return true;
    }

    return false;
}

int Doctors::GetIdxOf(Doctor &doctor) {
    for (int  i = 0 ; i < MAX && this->doctors[i] != NULL ; i ++)
        if (doctor == *(this->doctors[i])) return i;
    return -1;
}

int Doctors::FindDoctorByUserName(string &name) {
    for (int  i = 0 ; i < MAX && this->doctors[i] != NULL ; i += 1)
           if (name == this->doctors[i]->getName()) return i;
    return -1;
}

void Doctors::Update(string options) {

}

#endif //DOCTORS_H
