//
// Dependencies : NONE
//

#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>

using namespace std;

string GetString (const char* message) {
    cout << message;
    string str;
    cin.clear(); // ! clear previous buffer
    cin.sync(); // reset flags
    getline(cin , str);
    return str;
}

string PrintError (const char* message) { cout << "\n Error : " << message << " \n"; }

#endif //INPUT_H