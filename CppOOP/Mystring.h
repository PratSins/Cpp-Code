#ifndef _PLAYER_H_
#define _PLAYER_H_

class Mystring 
{
    private:
        char *str; // C-style string

    public:
        Mystring();
        Mystring(const char *s);
        Mystring(const Mystring &source);
        ~Mystring();

        Mystring &operator=(const Mystring &rhs);    // Copy assignment
        Mystring &operator=(Mystring &&rhs);          // Move assignment

        Mystring operator-() const;                             // make lowercase
        Mystring operator+(const Mystring &rhs) const;        // concatenate
        bool operator==(const Mystring &rhs) const;

        void display() const;
        int get_length() const;

        const char *get_str() const; // const functions can't change values of the data members
};

#endif // _PLAYER_H_