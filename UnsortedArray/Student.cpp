//#include <iostream> (Is included in student.h so not needed to include again)
#include "Student.h"

Student::Student()
{

}
Studnet::Student(string fidn)
{
    FIDN=fidn;
} 
void Studnet::setFN(string fn)
{
    FN=fn;
}
void Studnet::setLN(string ln)
{
    LN=ln;
}
    
string Studnet::getFIDN() const
{
    return FIDN;
}

string Studnet::getFN() const
{
    return FN;
}
string Studnet::getLN() const
{
    return LN;
}
    
friend ostream& operator<<(ostream& os, const Student& s) //output: "Hanks,Tom: A000"
{
    cout << s.LN << ", "<< s.FN<< ":"<< s.FIDN;
    
}