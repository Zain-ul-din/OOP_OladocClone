//
//
//

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <string>

using namespace std;

const char reserveSeparator = '`';

string Replace (string , const char  , const char );
template< class TYPE > TYPE Clamp (TYPE  , TYPE  , TYPE );

// Returns => String Replace old char with new
string Replace (string str , const char _old = ' ', const char _new  = '_') {
    string auxiliary;
    for (int  i = 0 ; i < str.length() ; i += 1)
        if (str[i] == _old) auxiliary.push_back(_new);
        else if (str[i] == reserveSeparator) auxiliary.push_back('?');
        else auxiliary.push_back(str[i]);
    return auxiliary;
}

// @ Returns => value btw min max
template<class TYPE>
TYPE Clamp(TYPE val, TYPE min , TYPE max) {
    if (val < min) return min;
    if (val > max) return max;
    return val;
}

#endif //ALGORITHM_H
