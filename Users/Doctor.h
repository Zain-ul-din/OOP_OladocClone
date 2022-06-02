//
// Dependencies : User.h
//

#ifndef DOCTOR_H
#define DOCTOR_H


#include "./User.h"


enum class Specialization {
    Gynecologist,
    Dermatologist,
    Oncologist,
    Orthopedic
};


class Doctor : public User {
public:
    /* Constructor */

    Doctor();

    Doctor(const string &name, const string &cnicNumber, const string &password, int experienceYears, float rating,
           const string &email, const string &hospitalName, const string &city, const string &specializationArea,
           int startingHour, int endingHours, double rates, double onLineRates, string &availableDays);

    /* Getter Setter */

    string getEmail() const;

    void setEmail(const string &email);

    int getExperienceYears() const;

    void setExperienceYears(int experienceYears);

    string getHospitalName() const;

    void setHospitalName(const string &hospitalName);

    string getCity() const;

    void setCity(const string &city);

    string getSpecializationArea() const;

    void setSpecializationArea(const string &specializationArea);

    int getStartingHour() const;

    void setStartingHour(int startingHour);

    int getEndingHours() const;

    void setEndingHours(int endingHours);

    double getRates() const;

    void setRates(double rates);

    double getOnLineRates() const;

    void setOnLineRates(double onLineRates);

    float getRating() const;

    void setRating(float rating);

    string getAvailableDays() const;

    void setAvailableDays(const string &availableDays);

    /* Overrides */

    void Update() override;

    /* Operator OverLoading */

    bool operator==(const Doctor &rhs) const;

    bool operator!=(const Doctor &rhs) const;

    /* IO */

    friend ostream &operator<<(ostream &os, const Doctor &doctor);

    friend ofstream &operator<<(ofstream &outFile, const Doctor &doctor);

    /* Static */

    static const string SpecializationList[4];

    static string GetSpecializationByIdx(int);

    /* Helpers */
    void InputSpecializationArea();

    void InputAppointmentsTime();

    void InputAvailableDays(bool canEdit);

private:
    int experienceYears;
    float rating;
    string email, hospitalName, city, specializationArea;
    int startingHour, endingHours; // 24 hours clock format
    double rates, onLineRates; // appointment rates
    string availableDays;
};

const string Doctor::SpecializationList[4] = {"Gynecologist", "Dermatologist", "Oncologist", "Orthopedic"};

string Doctor::GetSpecializationByIdx(int idx) {
    if (idx >= 0 && idx < 4) return SpecializationList[idx];
    return "NULL";
}

/* Constructor */

Doctor::Doctor() {
    this->email = "undefined";
    this->specializationArea = SpecializationList[0];
    this->experienceYears = 0;
    this->city = "undefined";
    this->hospitalName = "undefined";
    this->startingHour = 0;
    this->endingHours = 0;
    this->rates = 0;
    this->onLineRates = 0;
    this->rating = 0;
    this->availableDays = "";
}

Doctor::Doctor(const string &name, const string &cnicNumber, const string &password, int experienceYears, float rating,
               const string &email, const string &hospitalName, const string &city, const string &specializationArea,
               int startingHour, int endingHours, double rates, double onLineRates, string &availableDays) : User(name,
                                                                                                                  cnicNumber,
                                                                                                                  password),
                                                                                                             experienceYears(
                                                                                                                     experienceYears),
                                                                                                             rating(rating),
                                                                                                             email(email),
                                                                                                             hospitalName(
                                                                                                                     hospitalName),
                                                                                                             city(city),
                                                                                                             specializationArea(
                                                                                                                     specializationArea),
                                                                                                             startingHour(
                                                                                                                     startingHour),
                                                                                                             endingHours(
                                                                                                                     endingHours),
                                                                                                             rates(rates),
                                                                                                             onLineRates(
                                                                                                                     onLineRates),
                                                                                                             availableDays(
                                                                                                                     availableDays) {}

/* Getter Setter */

string Doctor::getEmail() const { return email; }

void Doctor::setEmail(const string &email) { this->email = email; }

int Doctor::getExperienceYears() const { return experienceYears; }

void Doctor::setExperienceYears(int experienceYears) { this->experienceYears = experienceYears; }

string Doctor::getHospitalName() const { return hospitalName; }

void Doctor::setHospitalName(const string &hospitalName) { this->hospitalName = hospitalName; }

string Doctor::getCity() const { return city; }

void Doctor::setCity(const string &city) { this->city = city; }

string Doctor::getSpecializationArea() const { return specializationArea; }

void Doctor::setSpecializationArea(const string &specializationArea) { this->specializationArea = specializationArea; }

int Doctor::getStartingHour() const { return startingHour; }

void Doctor::setStartingHour(int startingHour) { this->startingHour = startingHour; }

int Doctor::getEndingHours() const { return endingHours; }

void Doctor::setEndingHours(int endingHours) { this->endingHours = endingHours; }

double Doctor::getRates() const { return rates; }

void Doctor::setRates(double rates) { this->rates = rates; }

double Doctor::getOnLineRates() const { return onLineRates; }

void Doctor::setOnLineRates(double onLineRates) { this->onLineRates = onLineRates; }

float Doctor::getRating() const { return rating; }

void Doctor::setRating(float rating) { this->rating = rating; }

string Doctor::getAvailableDays() const { return this->availableDays; }

void Doctor::setAvailableDays(const string &availableDays) { this->availableDays = availableDays; }

/* Operator OverLoading */

bool Doctor::operator==(const Doctor &rhs) const {
    return this->email == rhs.email || this->cnicNumber == rhs.email || this->name == rhs.name;
}

bool Doctor::operator!=(const Doctor &rhs) const { return !(rhs == *this); }

ostream &operator<<(ostream &os, const Doctor &doctor) { return os; }

// File Write Format
ofstream &operator<<(ofstream &outFile, const Doctor &doctor) {
    outFile << Replace(doctor.name) << reserveSeparator
            << Replace(doctor.cnicNumber) << reserveSeparator
            << Replace(doctor.password) << reserveSeparator
            << Replace(doctor.email) << reserveSeparator
            << doctor.experienceYears << reserveSeparator
            << Replace(doctor.hospitalName) << reserveSeparator
            << Replace(doctor.city) << reserveSeparator
            << Replace(doctor.specializationArea) << reserveSeparator
            << doctor.startingHour << reserveSeparator
            << doctor.endingHours << reserveSeparator
            << doctor.rates << reserveSeparator
            << doctor.onLineRates << reserveSeparator
            << doctor.rating << reserveSeparator
            << doctor.availableDays << "\n";
    return outFile;
}

/* Overrides */

void Doctor::Update() {
    cout << "\n -- Edit Menu \n";
    cout << "  - Edit  specialization area        - 1\n";
    cout << "  - Edit location (city )            - 2\n";
    cout << "  - Edit hospital Name               - 3\n";
    cout << "  - Edit appointment starting timing - 4\n";
    cout << "  - Edit in-person fee               - 5\n";
    cout << "  - Edit online fee                  - 6\n";
    cout << "  - Edit Availability Days           - 7\n";
    cout << "  - Exit                             - 8\n";
    int choice = GetInput<int>("Enter Choice : ");
    switch (choice) {
        case 1:
            this->InputSpecializationArea();
            break;
        case 2:
            this->city = GetInput<string>("Enter new city name _ ");
            break;
        case 3:
            this->hospitalName = GetInput<string>("Enter new hospital name _ ");
            break;
        case 4:
            this->InputAppointmentsTime();
            break;
        case 5:
            this->rates = abs(GetInput<double>("Enter new in-person fee "));
            break;
        case 6: // Patient
            this->onLineRates = abs(GetInput<double>("Enter new online fee "));
            break;
        case 7:
            this->InputAvailableDays(true);
        default:
            cout << " -- Never Mind \n";
    }
}

void Doctor::InputSpecializationArea() {
    cout << "\n -- Select You're specialization area\n";
    for (int i = 0; i < 4; i += 1) cout << "  - " << SpecializationList[i] << " - " << i << "\n";
    int idx = GetInputInRange(0, 3, "Enter you're selection _  ", "Invalid Choice");
    this->specializationArea = GetSpecializationByIdx(idx);
    cout << "\n You Select _ " << specializationArea << "\n";
}

void Doctor::InputAppointmentsTime() {
    this->startingHour = Clamp(GetValueUpper<int>(0, "Enter appointments starting Time WRT => 24 Hour format _  ",
                                                  "Value must be greater then zero "), 1, 24);
    this->endingHours = Clamp(
            GetValueUpper<int>(this->startingHour, "Enter appointments ending Time WRT => 24 Hour format _  ",
                               "ending time must be greater then starting time"), 1, 24);
    cout << "\n\t timing : " << this->startingHour << " to " << this->endingHours << "\n";
}

void Doctor::InputAvailableDays(bool canEdit = false) {

        cout << "\n Enter In which days You'll be Available \n";
        cout << " - Full Week               - 0\n";
        cout << " - Weekend                 - 1 \n";
        cout << " - All Days except weekend - 2 \n";
        cout << " - Let Me Choose           - 3 \n";
        int userChoice = GetInputInRange(0, 3, " Enter Choice _ ", "Invalid Choice Please Select valid choice ");
        switch (userChoice)
    {
        case 0 :
            this->availableDays = "0123456";
            cout << " -- Added\n";
            break;
        case 1:
            this->availableDays = "56";
            cout << " -- Added\n";
        case 2:
            this->availableDays = "01234";
            cout << " -- Added\n";
        case 3:
                do
            {
                    cout << "\n Select in which Days You'll be Available \n";
                    cout << "  - Monday    - 0\n";
                    cout << "  - Tuesday   - 1\n";
                    cout << "  - Wednesday - 2\n";
                    cout << "  - Thursday  - 3\n";
                    cout << "  - Friday    - 4\n";
                    cout << "  - saturday  - 5\n";
                    cout << "  - sunday    - 6\n";

                    int choice = GetInput<int>("Select Day  _ ");
                    if (IsInRange(choice, 0, 6))
                {
                           cout << " Day : " << Time::daysName[choice] << "\n";
                           if (canEdit)
                        {
                            cout << " - Add Day    - 1 \n";
                            cout << " - Remove Day - 2 \n";
                            cout << " - Exit       - 3 \n";
                            int _choice = GetInput<int>("Enter choice _ ");
                            switch (_choice)
                        {
                            case 1:
                                if (IsContainsChar(this->availableDays, to_string(choice)))
                                    cout << " ! Already Added \n";
                                   else
                                {
                                    this->availableDays.push_back(to_string(choice)[0]);
                                    cout << " -- Added\n";
                                }
                            case 2:
                                RemoveChar(this->availableDays, to_string(choice)[0]);
                                cout << " -- Removed\n";
                            default:
                                cout << " -- Never Mind \n";
                        }
                    }       else
                    {
                        if (IsContainsChar(this->availableDays, to_string(choice)))
                            cout << " ! Already Added \n";
                        else
                            {
                              this->availableDays.push_back(to_string(choice)[0]);
                              cout << " -- Added\n";
                            }
                    }
                }       else PrintError("Invalid Choice");
            }
                       while (GetChoice("Do You Want to Edit More Days ( Y/N ) _ "));
            break;
        default:
            cout << " -- Never Mind \n";
    }
    cout << " -- All set\n";
}


#endif //DOCTOR_H
