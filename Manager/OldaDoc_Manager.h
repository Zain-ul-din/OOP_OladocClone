//
// Dependencies :
//

#ifndef OLDA_DOC_MANAGER_H
#define OLDA_DOC_MANAGER_H

#include "./Doctors.h"
#include "./Patients.h"

class OldaDoc_Manager {
public:


     void Show_DoctorPanel ();
     void Show_PatientPanel ();

private:
      Doctors doctors;

      void DoctorMenu ();
};

void OldaDoc_Manager::Show_DoctorPanel() {
       cout << "\n -- Doctor Panel \n";
       cout << "  - Login with existing account - 0\n";
       cout << "  - Sign Up new to OldaDoc      - 1\n";
       int choice = GetInput<int>("Enter Choice _ ");
       switch (choice)
    {
        case 0:
            this->doctors.SignIn();
            break;
        case 1:
            this->doctors.SignUp();
            break;
        default:
            PrintError("Invalid Choice \n");
    }

    if (this->doctors.currentLoggedInDoctorIdx != -1) DoctorMenu();
}

void OldaDoc_Manager::Show_PatientPanel() {

}

void OldaDoc_Manager::DoctorMenu () {
    cout << "\n -- Welcome to OldaDoc \n";
    cout << "\n  - View Profile       - 0 \n";
    cout << "\n  - Edit Profile       - 1 \n";
    cout << "\n  - Check Appointments - 2 \n";
}

#endif //OLDA_DOC_MANAGER_H
