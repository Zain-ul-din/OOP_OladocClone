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
    string appointmentStatus;
    string feedBack;
    static string appointmentsStatus[3];
};

string Appointment::appointmentsStatus[3] = { "approve" , "pending" "reject" };

#endif //APPOINTMENT_H
