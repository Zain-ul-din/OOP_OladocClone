/*
 * Following are the main Module of Oladoc
1. Appointment Management Module
2. Doctor Schedule Management Module
3. Patient Management Module
4. Doctor Management Module
5. Login Module
6. Registration Module
This system has three users. Admin, Doctor, and Patient. So all feature has been divided between these
three users.
 */

/*
 * Project Title : Oladoc HealthCare Clone
 * Language : c++
 * Dependencies : NONE
 */

#include "Login/PasswordValidator.h"
#include "./Login/EmailValidator.h"
#include "./Login/CnicValidator.h"
#include "./Users/User.h"

// Driver Code
int main () {

    std::string password = "Zain0l%i";
//    std:: string password;
//   std::cin>> password;
    if (ValidatePassword(password , 8)) std::cout << "True";
    else std::cout << "false";
    std::string email = "zain@gmail.com";
    if ( ValidateEmail(email , "@gmail.com") ){
        std::cout << "True";
    } else std::cout << "False";

    std::string cnic = "9032432940934";
    if (ValidateCnic(cnic)) {
        std::cout << "true";
    } else std::cout << "False";
    return 0;
}

/*
 * File System
 * => admin, doctor, and patient.
 */

/*
 * Panel  : Doctor Panel
 *
 */