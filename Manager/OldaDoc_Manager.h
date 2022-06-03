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
      Patients patients;

      void DoctorMenu ();
      void PatientPanel ();
};

void OldaDoc_Manager::Show_DoctorPanel() {
       cout << "\n -- Doctor Panel \n";
       cout << "  - Login with existing account     - 0\n";
       cout << "  - Sign Up ( new to OldaDoc )      - 1\n";
       cout << "  - Exit                            - 2\n";
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
            PrintError(" -- Exit \n");
    }

    if (this->doctors.currentLoggedInDoctorIdx != -1) DoctorMenu();
}

void OldaDoc_Manager::Show_PatientPanel() {
        cout << "\n -- Patient Panel \n";
        cout << "  - Login with existing account     - 0\n";
        cout << "  - Sign Up ( new to OldaDoc )      - 1\n";
        int choice = GetInput<int>("Enter Choice _ ");
        switch (choice)
    {
        case 0:
            this->patients.SignIn();
            break;
        case 1:
            this->patients.SignUp();
            break;
        default:
            PrintError(" -- Exit \n");
    }

    if (this->patients.currentLoggedInPatientIdx != -1)
        PatientPanel();
}

void OldaDoc_Manager::DoctorMenu () {
    cout << "\n -- Welcome to OldaDoc \n";
    cout << "\n  - View Profile       - 0 \n";
    cout << "\n  - Edit Profile       - 1 \n";
    cout << "\n  - Check Appointments - 2 \n";
    cout << "\n  - LogOut             - 3 \n";
    cout << "\n  - Exit               - 4 \n";
}

void OldaDoc_Manager::PatientPanel() {
    cout << "\n -- Welcome to OldaDoc \n";
    cout << "\n  - View Profile        - 0 \n";
    cout << "\n  - Edit Profile        - 1 \n";
    cout << "\n  - Search Doctors      - 2 \n";
    cout << "\n  - View Appointments   - 3 \n";
    cout << "\n  - LogOut              - 4 \n";
    cout << "\n  - Exit                - 5 \n";

}

#endif //OLDA_DOC_MANAGER_H
