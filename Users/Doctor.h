//
// Dependencies : NONE
//

#ifndef DOCTOR_H
#define DOCTOR_H

#include "./User.h"

class Doctor : public _User::User {

public:
    Doctor(const std::string &name, const std::string &cnicNumber, unsigned int password,
           const std::string &hospitalName, const std::string &specializationArea, const std::string &city,
           int experienceYears) : User(name, cnicNumber, password), hospitalName(hospitalName),
                                  specializationArea(specializationArea), city(city),
                                  experienceYears(experienceYears) {}

private:
    int experienceYears;
    std::string hospitalName  , specializationArea , city;
};

#endif //DOCTOR_H
