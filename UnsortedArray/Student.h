#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student{

public: 

    Student();
    Student(string fidn);
    
    void setFN(string fn);
    void setLN(string ln);
    
    string getFIDN() const;
    string getFN() const;
    string getLN() const;
    
    friend ostream& operator<<(ostream& os, const Student& s); //output: "Hanks,Tom: A000"

private:

   string FIDN; //the format should be "A000
   string FN;
   string LN;

};
#endif
