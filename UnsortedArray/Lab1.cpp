/*******************************************************************************
 * File: Lab1.cpp
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Test program for UnsortedListByArray class demonstrating
 *              student data management with duplicate prevention and list
 *              splitting functionality.
 * 
 * Test Features:
 * - Interactive student data entry with validation
 * - Duplicate FIDN prevention
 * - Student information management (FIDN, first name, last name)
 * - List splitting based on FIDN key values
 * - Input validation and capacity management
 * - List display and analysis
 * 
 * Data Structure: Unsorted array with student records
 * Algorithm: Linear search, list splitting, duplicate checking
 *******************************************************************************/

#include "Student.h"
#include "UnsortedListbyArray.h"
#include <iostream> 
#include <string>

using namespace std; 

int main()
{
    // ============================================================================
    // INITIALIZATION
    // ============================================================================
    
    UnsortedListByArray studentList, listOne, listTwo; // Create list objects
    string answer, key;                                // User input variables
    int MAX_ITEM = 6;                                  // Maximum students allowed
    
    cout<< "Please follow the prompt to enter students information, maximum number of students is 6. Type 'Y' to begin/continue, type 'N' to stop"<< endl; 
    cin >> answer;

    // ============================================================================
    // STUDENT DATA ENTRY LOOP
    // ============================================================================
    
    // Continue loop while user wants to add students and list isn't full
    while ((answer == "y" || answer == "Y")&& studentList.GetLength() < MAX_ITEM)
    {
        string fidn, fn, ln;  // Student data variables
        
        // Prompt for student information
        cout<<"Student No. "<< (studentList.GetLength() +1) << ":"<<endl;
        cout<< "Student FIDN"<< endl;
        cin >> fidn;  // Student FIDN (unique identifier)
        cout<< "Student First Name:"<< endl; 
        cin >> fn;    // Student first name
        cout<< "Student Last Name:"<< endl;
        cin >> ln;    // Student last name

        // Create student item with all information
        ItemType newItem;
        newItem.Initialize(fidn);  // Set FIDN as key
        newItem.setFN(fn);         // Set first name
        newItem.setLN(ln);         // Set last name
        
        // Attempt to insert student (checks for duplicates)
        if(studentList.NewInsertItem(newItem))
        {
            cout<<"A new Item has been inserted"<<endl;
        }
        else 
        {
           cout << "The item is not inserted since it is a duplicate." << endl;      
        }
        
        // Check if list is full or ask for continuation
        if(!studentList.IsFull())
        {
            cout << endl;
            cout << "Do you want to enter another student? (Y/N): "<<endl;
            cin >> answer; 
        }
        else
        {
           cout<< "The list is full, you have to stop."<<endl;
           cout<<endl;
        }
    }

    // ============================================================================
    // DISPLAY COMPLETE STUDENT LIST
    // ============================================================================
    
    cout << "You have entered "<< MAX_ITEM<< " students into the database"<< endl;
    cout << "This is the list"<< endl;
    studentList.Print();  // Display all students

    // ============================================================================
    // LIST SPLITTING OPERATION
    // ============================================================================
    
    cout<<endl;
    cout << "Please enter the FIDN as the key value to split the student list: "<< endl; 
    cin >> key;
    cout<<endl;
    
    // Create item for splitting operation
    ItemType item;
    item.Initialize(key);
    
    // Split list based on FIDN key
    studentList.SplitList (item ,listOne ,listTwo);

    // ============================================================================
    // DISPLAY SPLIT RESULTS
    // ============================================================================
    
    cout << "Split the previous list with,: "<< key <<endl;
    cout << "After split:"<<endl;
    cout << "list one is : "<< endl;
    listOne.Print();  // Display first split list
    cout<<endl; 
    cout<<endl;
    cout<< "list two is : "<<endl; 
    listTwo.Print();  // Display second split list
    cout<<endl; 
    cout<<endl;
    cout<<"After split, original list is : "<<endl; 
    studentList.Print();  // Display original list (unchanged)

    return 0;
}