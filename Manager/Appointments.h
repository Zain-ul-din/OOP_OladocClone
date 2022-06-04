//
//
//

#ifndef APPOINTMENTS_H
#define APPOINTMENTS_H

#include "../Users/Appointment.h"

#define MAX 100000

class Appointments  {
public:
    Appointments();

    Appointment** appointments;

    void LoadData ();
    void SaveData ();

    void MakeAppointment (Doctor& doctor, Patient patient);

    bool Search (Doctor& doctor , Patient& patient , Time& appointmentTime); // returns true if appointment time is same

    void Print (int idx , Doctor& doctor , Appointment& appointment);
    void Print (int idx , Patient& patient , Appointment& appointment);
    void Print (string user);
    int idx ;
private:
    static string APPOINTMENTS_FILEPATH ;
};

string Appointments::APPOINTMENTS_FILEPATH = "APPOINTMENTS_DATA.text";

Appointments::Appointments() {
     this->idx = -1;
     this->appointments = new Appointment*[MAX];
     for (int i = 0 ; i < MAX ; i += 1)
         this->appointments[i] = NULL;
     this->LoadData();
}

void Appointments::LoadData() {
     ifstream in;
     in.open(APPOINTMENTS_FILEPATH , ios::in);
     if (in.fail() || IsEmptyFile(in)) {
         in.close();
         this->SaveData();
         return;
     }
     string aux;
    while (getline(in , aux , '\n')){
       idx += 1;
       this->appointments[idx] = Appointment::StrToObj(aux);
    }
    in.close();
}

void Appointments::SaveData() {
    ofstream out;
    out.open(APPOINTMENTS_FILEPATH , ios::in);
    if (out.fail()) {
        out.close();
        return;
    }
    for (int i = 0 ; i < MAX && this->appointments[i] != NULL ; i +=1)
        out << *(this->appointments[i]);
    out.close();
}

void Appointments::MakeAppointment(Doctor &doctor, Patient patient) {
     Appointment appointment;
     Appointment * appointmentObj = appointment.MakeAppointment(doctor , patient);
     Time _time = appointmentObj->getAppointmentTime();
     if (Search(doctor , patient , _time)){
         PrintError("You can't have two appointments at a same time with same doctor ! ");
         delete appointmentObj;
         return;
     }
     idx += 1;
     this->appointments[idx] = appointmentObj;
     cout << "\n -- Appointment Succeed  \n";
     this->SaveData();
}

bool Appointments::Search(Doctor &doctor, Patient &patient, Time &appointmentTime) {
    for (int  i = 0 ; i < MAX && this->appointments[i] != NULL ; i += 1)
        if (doctor.getCnicNumber() == this->appointments[i]->getDoctorCnic() && patient.getCnicNumber() == this->appointments[i]->getPatientCnic())
            if (appointmentTime == this->appointments[i]->getAppointmentTime())
                return true;
    return false;
}

void Appointments::Print(int idx, Doctor &doctor , Appointment& appointment) {
    SetOffSet(idx, 9 , '|');
    SetOffSet(doctor.getName() , 12 , '|');
    SetOffSet(doctor.getEmail() , 20 , '|');
    SetOffSet(appointment.getAppointmentStatus() , 10 , '|');
    SetOffSet(appointment.getAppointmentType() , 8 , '|');
    cout << "\n";
}

void Appointments::Print(int idx, Patient &patient , Appointment& appointment) {
    SetOffSet(idx , 9 , '|');
    SetOffSet(patient.getName() , 12 , '|');
    SetOffSet(patient.getContactNumber() , 20 , '|');
    SetOffSet(appointment.getAppointmentStatus() , 10 , '|');
    SetOffSet(appointment.getAppointmentType() , 8 , '|');
    SetOffSet( patient.getAge() , 8 , '|');
    SetOffSet(appointment.getRating() , 6 , '|');
    SetOffSet(appointment.getRating() , 6 , '|');
    cout << "\n";
}

// Patient | Doctor
void Appointments::Print(string user) {
    cout << "\n\n";
    SetOffSet("Serial no" , 9 , '|');
    SetOffSet(user , 12 , '|');
    SetOffSet("Contact" , 20 , '|');
    SetOffSet("Status" , 10 , '|');
    SetOffSet("Type" , 8 , '|');
    if (user == "Patient") SetOffSet("Age" , 8 , '|');
    SetOffSet("Rating" , 6 , '|');
    cout << "\n";
}


#endif //APPOINTMENTS_H
