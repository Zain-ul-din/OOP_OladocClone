//
// Dependencies : User.h
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

class Doctor : public User {
public:
    /* Constructor */

    Doctor();
    Doctor(const std::string &name, const std::string &cnicNumber, unsigned int password, const std::string &email,
           int experienceYears, const std::string &hospitalName, const std::string &city,
           const std::string &specializationArea, int startingHour, int endingHours);

    /* Getter Setter */

    const std::string getEmail() const;
    void setEmail(const std::string &email);
    int getExperienceYears() const;
    void setExperienceYears(int experienceYears);
    const std::string getHospitalName() const;
    void setHospitalName(const std::string &hospitalName);
    const std::string getCity() const;
    void setCity(const std::string &city);
    const std::string getSpecializationArea() const;
    void setSpecializationArea(const std::string &specializationArea);
    int getStartingHour() const;
    void setStartingHour(int startingHour);
    int getEndingHours() const;
    void setEndingHours(int endingHours);

   /* Operator OverLoading */

   bool operator==(const Doctor &rhs) const;
   bool operator!=(const Doctor &rhs) const;


private:
    std::string email;
    int experienceYears;
    std::string hospitalName   , city;
    std::string specializationArea;
    int startingHour , endingHours ;

    static const std::string SpecializationList[4] ;
};

const std::string Doctor::SpecializationList[4] = {
        "Gynecologist" ,
        "Dermatologist" ,
        "Oncologist" ,
        "Orthopedic"
};

Doctor::Doctor() {
    this->email = "undefined";
    this->specializationArea = SpecializationList[0];
    this->experienceYears = 0;
    this->city = "undefined";
    this->hospitalName = "undefined";
    this->startingHour = 0;
    this->endingHours = 0;
}

/* Constructor */
Doctor::Doctor(const std::string &name, const std::string &cnicNumber, unsigned int password, const std::string &email,
               int experienceYears, const std::string &hospitalName, const std::string &city,
               const std::string &specializationArea, int startingHour, int endingHours) : User(name, cnicNumber,
                                                                                                password), email(email),
                                                                                           experienceYears(
                                                                                                   experienceYears),
                                                                                           hospitalName(hospitalName),
                                                                                           city(city),
                                                                                           specializationArea(
                                                                                                   specializationArea),
                                                                                           startingHour(startingHour),
                                                                                           endingHours(endingHours) {}
/* Getter Setter */

const std::string Doctor::getEmail() const { return email;}
void Doctor::setEmail(const std::string &email) {this->email = email;}
int Doctor::getExperienceYears() const {return experienceYears;}
void Doctor::setExperienceYears(int experienceYears) {this->experienceYears = experienceYears;}
const std::string Doctor::getHospitalName() const { return hospitalName;}
void Doctor::setHospitalName(const std::string &hospitalName) { this->hospitalName = hospitalName;}
const std::string Doctor::getCity() const { return city;}
void Doctor::setCity(const std::string &city) { this->city = city;}
const std::string Doctor::getSpecializationArea() const { return specializationArea;}
void Doctor::setSpecializationArea(const std::string &specializationArea) {this->specializationArea = specializationArea;}
int Doctor::getStartingHour() const { return startingHour;}
void Doctor::setStartingHour(int startingHour) {this->startingHour = startingHour;}
int Doctor::getEndingHours() const {return endingHours;}
void Doctor::setEndingHours(int endingHours) {this->endingHours = endingHours;}

/* Operator OverLoading */

bool Doctor::operator==(const Doctor &rhs) const { return this->email == rhs.email || this->cnicNumber == rhs.email;}
bool Doctor::operator!=(const Doctor &rhs) const { return !(rhs == *this);}


#endif //DOCTOR_H
