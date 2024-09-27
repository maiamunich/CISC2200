#include "Student.h"

int main()
{
    string answer;
    string FIDN, FN, LN;
   cout<< "Please follow the prompt to enter students information, maximum number of
students is 6. Type "Y" to begin/continue, type "N" to stop"<< endl; 
    cin >> answer;
// create a while loop that checks that we dont go over the maxium abount of student '6' and gives the user the options of yes or no 

    while (answer == "y" || "Y")
    {

    //inside of the while loop
    // read off students No. (make sure that this counts for if a student is repeated)
    cout<<"Student No. "<< //(What data type do i put here )<< ":"<<endl;
    cout<< "Student FIDN"<< endl;
    cin>> FIDN;
    cout<< "Student First Name:"<< endl; 
    cin>> FN; 
    cout<< "Student Last Name:"<< endl;
    cin>>LN;
    //students fidn
    //students first name 
    //students last name
    cout<<"A new item is inserted"<< endl; 
    }

    // let user know that a new item has been inserted
    //let user know if item was not inserted since it was a duplicate
//out side while loop 
// as user if they want to contine
//when while loop finished let them know they have reached the max capacity of students they could enter
// output all students using print function 

// as for FIDN for the key value to split the tudent list
//show the lists split (listone and listtwo)
//show original list 
    return 0;
}