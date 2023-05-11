#ifndef _Mystring22_H_
#define _Mystring22_H_

class Mystring2 {
    friend bool operator==(const Mystring2 &lhs, const Mystring2 &rhs);
    friend Mystring2 operator-(const Mystring2 &obj);
    friend Mystring2 operator+(const Mystring2 &lhs, const Mystring2 &rhs);
private:
    char *str;      // pointer to a char[] that hold a C-style string
public:
    Mystring2();
    Mystring2(const char *s);
    Mystring2(const Mystring2 &source);
    Mystring2( Mystring2 &&source);
    ~Mystring2();
    
    Mystring2 &operator=(const Mystring2 &rhs);
    Mystring2 &operator=(Mystring2 &&rhs);
   
    void display() const;

    int get_length() const;
    const char *get_str() const;
};

#endif // _Mystring2_H_
