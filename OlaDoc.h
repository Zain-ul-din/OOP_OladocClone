//
// Created by 97152 on 31/05/2022.
//

#ifndef OLADOC_H
#define OLADOC_H

#include <string>
#include "./Users/Doctor.h"
#include "./FileManager/SaveSystem.h"

#define MAX 100000

using namespace std;

class OlaDoc {
public:
    OlaDoc();
private:
      Doctor** doctors = NULL;
      const string DOCTORS_FILEPATH = "DOCTOR_DATA.text" ;

      // Helper's
      void LoadDataFromFiles () ;
      void FillArray ();
};

OlaDoc::OlaDoc() {
    this->doctors = new Doctor*[MAX];
    FillArray();
}

void OlaDoc::LoadDataFromFiles() {
    ifstream in;
    in.open(this->DOCTORS_FILEPATH , ios::in);
    if (in.fail() || IsEmptyFile(in)) return;
    string auxiliary = "";
    while (getline(in , auxiliary , '\n')) {
        // do some logic with auxiliary
    }
    in.close();
}

void OlaDoc::FillArray() {
   for (int i = 0 ; i < MAX ; i += 1) this->doctors[i] = NULL;
}

#endif //OLADOC_H
