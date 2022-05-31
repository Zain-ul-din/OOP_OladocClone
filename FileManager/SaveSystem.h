//
// Dependencies : NONE
//

#ifndef SAVESYSTEM_H
#define SAVESYSTEM_H

// @ SaveSystem Base Class
template<class Type>
class ISaveAble  {
public:
    virtual std::string ToString () = 0;
    virtual std::string ToObj (std::string& objStr) = 0;
};

#endif //SAVESYSTEM_H


//13-digit CNIC