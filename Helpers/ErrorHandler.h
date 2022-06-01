//
// Created by 97152 on 01/06/2022.
//

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <iostream>
#include <string>

using namespace std;

void TrowError (string errType) {
    cout << "\n" << " !! Error _ ";
    switch (errType) {
        case "duplicate_acc":
            cout << "Account Already Exists Please Use Sign In Instead";
        break;

        default:
            cout << "NULL";
    }
    cout << " .\n";
}

#endif //ERRORHANDLER_H
