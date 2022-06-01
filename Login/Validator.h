//
// Dependencies : NONE
//

#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "../Helpers/Input.h"


bool ValidatePassword(string &, const int);
bool ValidateEmail(string &, string);
bool ValidateCnic(string &);


/* Validates Password
   @ Params : std::string & pass , const int len
   @ Returns : Boolean */
bool ValidatePassword(string &password, const int length) {
    bool isValid = false;
    // Length Validator
    if (password.length() < length) return false;

    //  Digit Validator
    const std::string NUMBERS = "0123456789";
    for (int i = 0; i < password.length(); i += 1)
        for (int idx = 0; idx < NUMBERS.length(); idx += 1)
            if (password[i] == NUMBERS[idx]) isValid = true;

    if (!isValid) return false;
    isValid = false;

    // Case Validator
    bool hasUpperCase = false, hasLowerCase = false;
    const string albet_l = "abcdefghijklmnopqrstuvwxyz";
    const string albet_u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < password.length(); i += 1)
        for (int idx = 0; idx <= 26; idx += 1) {
            if (password[i] == albet_l[idx]) hasLowerCase = true;
            if (password[i] == albet_u[idx]) hasUpperCase = true;
        }
    isValid = hasLowerCase && hasUpperCase;

    if (!isValid) return false;
    isValid = false;

    // Symbol Validator
    const string SYMBOLS = "!@#$%^&*(){}[]?<>_";
    for (int i = 0; i < password.length(); i += 1)
        for (int idx = 0; idx < SYMBOLS.length(); idx += 1)
            if (password[i] == SYMBOLS[idx]) isValid = true;

    return isValid;
}

/* Validates Emails
@ Params : std::string & email , std::string match
@ Returns : Boolean */
bool ValidateEmail(string &email, string match) {
    const int minEmailLen = 2;
    bool isValid = false;

    // Length Validator
    int len = email.length() - match.length();
    isValid = len >= minEmailLen;


    if (!isValid) return false;
    isValid = false;

    // match Validator
    int emailIdx = email.length(), matchIdx = match.length();
    while (matchIdx--) {
        emailIdx -= 1;
        if (email[emailIdx] != match[matchIdx]) return false;
    }

    // email Body Validator
    int symbolCount = 0;
    const string SYMBOLS = "!#$%^&*(){}[]?<>";
    for (int i = 0; i < email.length(); i += 1) {
        for (int idx = 0; idx < SYMBOLS.length(); idx += 1)
            if (email[i] == SYMBOLS[idx]) return false;
        if (email[i] == '@') symbolCount += 1;
    }

    isValid = symbolCount == 1;
    return isValid;
}

/*
 Validates Cnic Number
  @ Params : std::string cnic
  @ Returns : Boolean
*/
bool ValidateCnic(string &cnic) {
    bool isValid = false;

    // Length Validator
    if (cnic.length() != 13) return false;

    // Numbers Validator
    const std::string NUMBERS = "0987654321";
    for (int i = 0; i < cnic.length(); i += 1) {
        bool isFound = false;
        for (int idx = 0; idx < NUMBERS.length(); idx += 1)
            if (cnic[i] == NUMBERS[idx]) isFound = true;
        if (!isFound) return false;
    }

    isValid = NUMBERS[0] != cnic[0];
    return isValid;
}


#endif //VALIDATOR_H
