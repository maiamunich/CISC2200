//#include <iostream> (Is included in student.h so not needed to include again)
#include "Student.h"

Student::Student()
{

}
Student::Student(string fidn)
{
   this->FIDN=fidn;
} 
void Student::setFN(string fn)
{
    this->FN=fn;
}
void Student::setLN(string ln)
{
    this->LN=ln;
}
    
string Student::getFIDN() const
{
    return FIDN;
}

string Student::getFN() const
{
    return FN;
}
string Student::getLN() const
{
    return LN;
}
    
ostream& operator<<(ostream& os, const Student& s) //output: "Hanks,Tom: A000"
{
    os<< s.LN << ", "<< s.FN<< ":"<< s.FIDN;
    return os;
    
}