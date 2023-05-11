#include <iostream>
#include <cstring>
#include <cctype>
#include "Mystring2.h"

// No-args constructor
Mystring2::Mystring2() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring2::Mystring2(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s)+1];
            std::strcpy(str, s);
        }
}

// Copy constructor
Mystring2::Mystring2(const Mystring2 &source) 
    : str{nullptr} {
        str = new char[std::strlen(source.str)+ 1];
        std::strcpy(str, source.str);
        std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring2::Mystring2( Mystring2 &&source) 
    :str(source.str) {
        source.str = nullptr;
        std::cout << "Move constructor used" << std::endl;
}

// Destructor
Mystring2::~Mystring2() {
    delete [] str;
}

// Copy assignment operator
Mystring2 &Mystring2::operator=(const Mystring2 &rhs) {
    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

// Move assignment operator
Mystring2 &Mystring2::operator=( Mystring2 &&rhs) {
    std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display method
void Mystring2::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
 int Mystring2::get_length() const { return std::strlen(str); }
 
 // string getter
 const char *Mystring2::get_str() const { return str; }


// Equality
bool operator==(const Mystring2 &lhs, const Mystring2 &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// Make lowercase
Mystring2 operator-(const Mystring2 &obj) {
    char *buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for (size_t i=0; i<std::strlen(buff); i++) 
        buff[i] = std::tolower(buff[i]);
    Mystring2 temp {buff};
    delete [] buff;
    return temp;
}

// Concatenation
Mystring2 operator+(const Mystring2 &lhs, const Mystring2 &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring2 temp {buff};
    delete [] buff;
    return temp;
}

