//
//
//

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "./User.h"

class Appointment {
public:

private:

    string doctorCnic , patientCnic;
    double appointmentCost;
    Time appointmentTime;
    string appointmentType;

    static string appointmentStatus[3];
};

string Appointment::appointmentStatus[3] = { "approve" , "pending" "reject" };

#endif //APPOINTMENT_H
