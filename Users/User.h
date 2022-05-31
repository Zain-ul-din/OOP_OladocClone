//
// Dependencies :- NONE
//
#ifndef USER_H
#define USER_H

namespace _User {
    class User;
}
// @ User Base Class
class _User::User {
public:
    /* Constructor */
    User(const std::string &name, const std::string &cnicNumber, unsigned int password) : name(name),
                                                                                          cnicNumber(cnicNumber),
                                                                                          password(password) {}
    User() {
        this->name = name;
        this->cnicNumber = "";
        this->password = 0;
    }

    /* Getter &  Setter's */

    const std::string &getName() const { return name; }
    void setName(const std::string &name) { this->name = name;}
    const std::string &getCnicNumber() const { return cnicNumber;}
    void setCnicNumber(const std::string &cnicNumber) { this->cnicNumber = cnicNumber;}
    unsigned int getPassword() const { return password;}
    void setPassword(unsigned int password) { this->password = password;}
protected:
    std::string name;
    std::string cnicNumber;
    unsigned int password;
};

#endif //USER_H
