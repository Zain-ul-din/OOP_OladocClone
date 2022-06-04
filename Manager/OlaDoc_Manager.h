//
// Dependencies :
//

#ifndef OLDA_DOC_MANAGER_H
#define OLDA_DOC_MANAGER_H

#include "./Doctors.h"
#include "./Patients.h"
#include "./Appointments.h"

class OlaDoc_Manager {
public:

     void Show_DoctorPanel ();
     void Show_PatientPanel ();

private:
      Doctors doctors;
      Patients patients;
      Appointments appointments;

      void DoctorMenu ();
      void PatientMenu ();

      void SearchDoctors_Menu();
      void Appointments_Menu();

      // Helpers
      void ShowDoctorAppointments ();
      void ShowPatientAppointments ();
};

void OlaDoc_Manager::Show_DoctorPanel() {
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
    system("pause");
    if (this->doctors.currentLoggedInDoctorIdx != -1) DoctorMenu();
}

void OlaDoc_Manager::Show_PatientPanel() {
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

    system("pause");
    if (this->patients.currentLoggedInPatientIdx != -1)
        PatientMenu();
}

void OlaDoc_Manager::DoctorMenu () {
          int choice = 0;
          for (; choice != 3 ;)
    {
          system("cls");
          cout << "\n -- Welcome to OldaDoc \n";
          cout << "\n  - View Profile       - 0 \n";
          cout << "\n  - Edit Profile       - 1 \n";
          cout << "\n  - Check Appointments - 2 \n";
          cout << "\n  - LogOut             - 3 \n";
          choice = GetInput<int>("Enter Choice : ");
          switch (choice)
        {
            case 0:
                this->doctors.doctors[this->doctors.currentLoggedInDoctorIdx]->Display();
                break;
            case 1:
                this->doctors.doctors[this->doctors.currentLoggedInDoctorIdx]->Update();
                this->doctors.SaveData();
                break;
            case 2:
                this->ShowDoctorAppointments();
                break;
            case 3:
                this->doctors.currentLoggedInDoctorIdx = -1;
                cout << " -- Logged Out \n";
                break;
            default:
                PrintError("Invalid Choice ! ");
        }
        system("pause");
    }
}

void OlaDoc_Manager::PatientMenu() {
    int choice = 0;
    for ( ; choice != 4 ;)
    {
        system("cls");
        cout << "\n -- Welcome to OldaDoc \n";
        cout << "\n  - View Profile        - 0 \n";
        cout << "\n  - Edit Profile        - 1 \n";
        cout << "\n  - Search Doctors      - 2 \n";
        cout << "\n  - View Appointments   - 3 \n";
        cout << "\n  - LogOut              - 4 \n";
        choice = GetInput<int>("Enter Choice : ");
        switch (choice)
        {
            case 0:
                   this->patients.patients[this->patients.currentLoggedInPatientIdx]->Display();
            break;
            case 1:
                   this->patients.patients[this->patients.currentLoggedInPatientIdx]->Update();
                   this->patients.SaveData();
            break;
            case 2:
                   this->SearchDoctors_Menu();
            break;
            case 3:
                   this->ShowPatientAppointments();
            break;
            case 4:
                   this->patients.currentLoggedInPatientIdx = -1;
            break;
            default:
                PrintError("Invalid Choice ! ");
        }
        system("pause");
    }

}

void OlaDoc_Manager::SearchDoctors_Menu() {
    int choice = 0;
    for ( ; choice != 4 ; )
    {
        system("cls"); //Patient can search for doctors by (Specialty, Area, and Hospitals)

        cout << "\n -- Welcome to OldaDoc Search Menu . Here you can find best doctors in less time  \n";
        cout << "\n  - Search doctor by Specialty - 0 \n" ;
        cout << "\n  - Search doctor by Area      - 1 \n" ;
        cout << "\n  - Search doctor by Hospital  - 2 \n" ;
        cout << "\n  - Let me choose              - 3 \n" ;
        cout << "\n  - Exit                       - 4 \n" ;
        choice = GetInput<int>("Enter Choice : ");
        string match , match1 , match2;
        bool isFound ;
        switch (choice)
        {
            case 0:
                match = Doctor::GetSpecializationAreaInput();
                isFound = this->doctors.Search(match , "Specialty");
                if (!isFound) cout << "\t\t -- Not Found \n";
                else Appointments_Menu();
            break;
            case 1:
                match = GetString("Enter doctor Area (city name) : ");
                isFound = this->doctors.Search(match , "Area");
                if (!isFound) cout << "\t\t -- Not Found \n";
                else Appointments_Menu();
            break;
            case 2:
                match = GetString("Enter Hospital Name : ");
                isFound = this->doctors.Search(match , "Hospital");
                if (!isFound) cout << "\t\t -- Not Found \n";
                else Appointments_Menu();
            break;
            case 3:
                        for ( ; choice != 4 ; )
                {
                        system("cls");
                        cout << "\n - Search by Specialty + Area            - 0\n";
                        cout << "\n - Search by Hospital + Specialty        - 1\n";
                        cout << "\n - Search by Area + Hospital             - 2\n";
                        cout << "\n - Search by Specialty + Area + Hospital - 3\n";
                        cout << "\n - Exit                                  - 4\n";
                        choice = GetInput<int>("Enter Choice : ");
                        switch (choice)
                    {
                        case 0:
                            match = Doctor::GetSpecializationAreaInput();
                            match1 = GetString("Enter doctor Area (city name) : ");
                            isFound = this->doctors.Search(match , match1  , "Specialty+Area");
                            if (isFound) Appointments_Menu();
                            break;
                        case 1:
                            match = GetString("Enter Hospital Name : ");
                            match1 = Doctor::GetSpecializationAreaInput();
                            isFound = this->doctors.Search( match, match1, "Hospital+Specialty");
                            if (isFound) Appointments_Menu();
                            break;
                        case 2:
                            match = GetString("Enter doctor Area (city name) : ");
                            match1 = GetString("Enter Hospital Name : ");
                            isFound = this->doctors.Search( match, match1, "Area+Hospital");
                            if (isFound) Appointments_Menu();
                            break;
                        case 3:
                            match = Doctor::GetSpecializationAreaInput();
                            match1 = GetString("Enter doctor Area (city name) : ");
                            match2 = GetString("Enter Hospital Name : ");
                            isFound = this->doctors.Search(match , match1 , match2
                                  , GetChoice(" >> Do you want to match all queries Y/N : "));
                            if (isFound) Appointments_Menu();
                            break;
                        case 4:
                            cout << " -- Exit \n";
                            break;
                        default:
                            PrintError("Invalid Choice");
                    }
                    if (!isFound) cout << "\t\t -- Not Found \n";

                    system("pause");
                }
                choice = 0;
            break;
            case 4:
                cout << " -- Exit \n";
            break;
            default:
                PrintError("Invalid Choice ! ");
        }
        system("pause");
    }
}

void OlaDoc_Manager::Appointments_Menu() {
    if (!GetChoice("Do You want to make Appointment with any of these doctors Y/N : ")) return;
    int idx = GetInput<int>("Enter Serial No of doctor for more details : ");
    if (!this->doctors.Search(idx)) {
        PrintError("Invalid Serial Number !! ");
        return;
    }
    system("cls");
    cout << *(this->doctors.doctors[idx]) ;
    PrintChar('-' , 100);
    if (!GetChoice("Do you want to make appointment with this doctor Y/N : ")) return;
    this->appointments.MakeAppointment(*(this->doctors.doctors[idx] ), *(this->patients.patients[this->patients.currentLoggedInPatientIdx]));
}

void OlaDoc_Manager::ShowDoctorAppointments() {
    appointments.Print("Patient");
    if (appointments.idx == -1) {
        cout << "No Appointment So far \n";
        return;
    }
    int idx = appointments.idx + 1;
    bool isFound = false;
    while (idx --) {
        if (appointments.appointments[idx] == NULL) break;
        appointments.Print(idx
             , *(patients.Search(appointments.appointments[idx]->getPatientCnic() ) )
             , *(this->appointments.appointments[idx]));
        isFound = true;
    }
    if (!isFound) cout << " \n -- No Appointment So far \n";
}

void OlaDoc_Manager::ShowPatientAppointments() {
    appointments.Print("Doctor");
    if (appointments.idx == -1) {
        cout << "No Appointment So far \n";
        return;
    }
    int idx = appointments.idx + 1;
    bool isFound = false;
    while (idx --) {
        if (appointments.appointments[idx] == NULL) break;
        appointments.Print(idx
                , *(doctors.Search(this->appointments.appointments[idx]->getDoctorCnic() , true))
                , *(this->appointments.appointments[idx]));
        isFound = true;
    }
    if (!isFound) cout << " \n -- Empty \n";
}

#endif //OLDA_DOC_MANAGER_H
