//
// Dependencies : NONE
//

#ifndef DOCTOR_H
#define DOCTOR_H

#include "./User.h"

enum class Specialization{
    Gynecologist  ,
    Dermatologist ,
    Oncologist ,
    Orthopedic
};

class Doctor : public _User::User {
public:
    /* Constructor */

    Doctor(const std::string &name, const std::string &cnicNumber, unsigned int password, const std::string &email,
           int experienceYears, const std::string &hospitalName, const std::string &city,
           Specialization specializationArea);

    Doctor();

    /* Getter Setter */

    const std::string &getEmail() const;
    void setEmail(const std::string &email);
    int getExperienceYears() const;
    void setExperienceYears(int experienceYears);
    const std::string &getHospitalName() const;
    void setHospitalName(const std::string &hospitalName);
    const std::string &getCity() const;
    void setCity(const std::string &city);
    std::string getSpecializationArea() ;
    void setSpecializationArea(Specialization specializationArea);

private:
    std::string email;
    int experienceYears;
    std::string hospitalName   , city;
    Specialization specializationArea;

    static const std::string SpecializationList[4] ;
    static int GetIdxOfSpecialization (Specialization specialization);
    static Specialization GetSpecializationByStr (std::string&);
};

const std::string Doctor::SpecializationList[4] = {
        "Gynecologist" ,
        "Dermatologist" ,
        "Oncologist" ,
        "Orthopedic"
};

Doctor::Doctor(const std::string &name, const std::string &cnicNumber, unsigned int password, const std::string &email,
               int experienceYears, const std::string &hospitalName, const std::string &city,
               Specialization specializationArea) : User(name, cnicNumber, password), email(email),
                                                    experienceYears(experienceYears), hospitalName(hospitalName),
                                                    city(city), specializationArea(specializationArea) {}


const std::string &Doctor::getEmail() const { return email;}
void Doctor::setEmail(const std::string &email) { this->email = email;}
int Doctor::getExperienceYears() const { return experienceYears;}
void Doctor::setExperienceYears(int experienceYears) { this->experienceYears = experienceYears;}
const std::string &Doctor::getHospitalName() const { return hospitalName;}
void Doctor::setHospitalName(const std::string &hospitalName) { this->hospitalName = hospitalName;}
const std::string &Doctor::getCity() const { return city;}
void Doctor::setCity(const std::string &city) { this->city = city;}
std::string Doctor::getSpecializationArea()  { return SpecializationList[GetIdxOfSpecialization(this->specializationArea)]; }
void Doctor::setSpecializationArea(Specialization specializationArea) {this->specializationArea = specializationArea;}

int Doctor::GetIdxOfSpecialization(Specialization specialization) {
    switch(specialization) {
        case Specialization::Gynecologist:
            return 0;
        case Specialization::Dermatologist:
            return 1;
        case Specialization::Oncologist:
            return 2;
        case Specialization::Orthopedic:
            return 3;
    }
    return 0;
}

Doctor::Doctor() {
    this->email = "undefined";
    this->specializationArea = Specialization::Gynecologist;
    this->experienceYears = 0;
    this->city = "undefined";
    this->hospitalName = "undefined";
}

Specialization Doctor::GetSpecializationByStr(std::string &specialization) {
         if (specialization == "Gynecologist") return Specialization::Gynecologist;
         if (specialization == "Dermatologist") return Specialization::Dermatologist;
         if (specialization == "Oncologist") return Specialization::Oncologist;
         if (specialization == "Orthopedic")  return Specialization::Orthopedic;

         return Specialization::Gynecologist;
}


#endif //DOCTOR_H
