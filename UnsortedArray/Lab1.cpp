#include "Student.h"
#include "UnsortedListbyArray.h"
#include <iostream> 
#include <string>

using namespace std; 

int main()
{
    UnsortedListByArray studentList; //Create an UnsortedListByArray Object
    string answer;
    int MAX_ITEM = 6; 
    cout<< "Please follow the prompt to enter students information, maximum number of students is 6. Type 'Y' to begin/continue, type 'N' to stop"<< endl; 
    cin >> answer;
// create a while loop that checks that we dont go over the maxium abount of student '6' and gives the user the options of yes or no 

    while ((answer == "y" || answer == "Y")&& studentList.GetLength() < MAX_ITEM)
    {
        string fidn, fn, ln;
        //inside of the while loop
        // read off students No. (make sure that this counts for if a student is repeated)
        cout<<"Student No. "<< (studentList.GetLength() +1) << ":"<<endl;//(What data type do i put here )
        cout<< "Student FIDN"<< endl;
        cin >> fidn; //could this and the other two be setFIDN and SetFN and SetLN //students fidn
        cout<< "Student First Name:"<< endl; 
        cin >> fn;         //students first name 
        cout<< "Student Last Name:"<< endl;
        cin >> ln;        //students last name

        ItemType newItem;
        newItem.Initialize(fidn);
        newItem.setFN(fn);
        newItem.setLN(ln);
    
        bool found = false; 
        ItemType currentPos; 

        for (int i = 0; i < studentList.GetLength(); i++)
        {
            studentList.RetrieveItem(currentPos, i);
            if(newItem.ComparedTo(currentPos)==EQUAL)
            { 
                found = true; 
                break;
            }
        }
        
        if(found)
        {
            cout << "The item is not inserted since it is a duplicate"<<endl;
        }
        else 
        {
            studentList.NewInsertItem(newItem);
            cout << "A new student has been inserted." << endl; 
        }

        if(studentList.GetLength()<MAX_ITEM)
        {
            cout << "Do you want to enter another student? (Y/N): ";
            cin >> answer; 
        }
        else
        {
           cout<< "Maximum number of students reached. Cannot add more students."<<endl;
        }

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