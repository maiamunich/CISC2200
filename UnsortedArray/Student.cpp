//#include <iostream> (Is included in student.h so not needed to include again)
#include "Student.h"

Student::Student()
{

}
Student::Student(string fidn)
{
    FIDN=fidn;
} 
void Student::setFN(string fn)
{
    FN=fn;
}
void Student::setLN(string ln)
{
    LN=ln;
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
    
friend ostream& operator<<(ostream& os, const Student& s) //output: "Hanks,Tom: A000"
{
    os<< s.LN << ", "<< s.FN<< ":"<< s.FIDN;
    
}