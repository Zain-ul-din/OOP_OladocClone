//
// Dependencies : STD
//

#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string>

using namespace std;

void PrintError (const char*);
string GetString (const char*);
bool GetChoice (const char*);

template<class TYPE> TYPE GetInput (const char*);
template<class TYPE> TYPE GetValueUnder (TYPE  , const char* , const char* );
template<class TYPE> TYPE GetValueUpper (TYPE , const char* , const char*);
template<class TYPE> TYPE GetInputInRange ( TYPE , TYPE   , const char * , const char *);

// @ Get input in give range from user
template<class TYPE>
TYPE GetInputInRange( TYPE min , TYPE max , const char * message , const char* err ) {
    TYPE aux ;
    aux = GetInput<TYPE>(message);
    if (aux >= min && aux <= max) return aux;
    PrintError(err);
    GetInputInRange( min , max , message , err);
}

// @ Displays Error
void PrintError (const char* message) { cout << "\n Error : " << message << " \n"; }

// @ Gets String Input
string GetString (const char* message) {
    cout << message;
    string str;
    cin.clear(); // ! clear previous buffer
    cin.sync(); // reset flags
    getline(cin , str);
    return str;
}

// @ Gets  input of Type <Any>
template<class TYPE>
TYPE GetInput (const char* message) {
    cout << message;
    TYPE auxiliary ;
    cin.clear(); // ! clear previous buffer
    cin.sync(); // reset flags
    cin >> auxiliary;
    if (!cin.fail()) return auxiliary;
    PrintError("Invalid Input Expected : number");
    GetInput<TYPE>(message);
    return auxiliary;
}

// @ Returns new Value that must be under the given value
template<class TYPE>
TYPE GetValueUnder(TYPE value , const char* message , const char* err) {
    TYPE auxiliary = GetInput<TYPE>(message);
    if (auxiliary < value) return value;
    PrintError(err);
    GetValueUnder<TYPE>(value , message , err);
}

// @ Returns new Value that must be greater then given value
template<class TYPE> TYPE GetValueUpper (TYPE value , const char* message , const char* err) {
    TYPE auxiliary = GetInput<TYPE>(message);
    if (auxiliary > value) return value;
    PrintError(err);
    GetValueUpper<TYPE>(value , message , err);
}

// Returns => User Choice Y/N
bool GetChoice(const char *message) {
    cout << message;
    char aux;
    cin >> aux;
    return aux == 'Y' || aux == 'y';
}

#endif //INPUT_H
