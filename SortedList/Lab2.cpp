/*******************************************************************************
 * File: Lab2.cpp
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Test program for SortedListByArray class demonstrating
 *              sorted list operations including insertion, merging, and
 *              list management with user input validation.
 * 
 * Test Features:
 * - Interactive list building with size validation
 * - Sorted insertion demonstration
 * - List merging algorithm testing
 * - Input validation and error handling
 * - List display and analysis
 * 
 * Algorithm: Merge algorithm for combining two sorted lists efficiently
 *******************************************************************************/

#include "SortedListByArray.h"
#include <iostream> 
#include <string>

using namespace std; 

int main()
{
    // ============================================================================
    // INITIALIZATION
    // ============================================================================
    
    SortedListByArray listOne, listTwo, MergedList;  // Create three list objects
    ItemType item1, item2;                           // Items for operations
    int length1, length2;                           // Lengths for user input
    int space1, space2;                             // Values for items

    // ============================================================================
    // FIRST LIST CREATION
    // ============================================================================
    
    cout<< "Please enter how long the List one is (maximum length "<< MAX_ITEM<< "): ";
    cin >> length1;
    
    // Validate input length
    while(length1 > MAX_ITEM)
    {
        cout<< "The amount you have entered is above "<< MAX_ITEM<<endl;
        cout<< "Please enter a new amount for how long List One is: "<<endl;
        cin >> length1;
    }
    
    // Build first list with user input
    for(int a = 0; a <length1; a++)
    {
        cout<<"Insert the number for position "<< a + 1<< ":" << endl;
        cin>> space1;
        item1.Initialize(space1);
        listOne.InsertItem(item1);  // Insert maintains sorted order
    }
    listOne.Print();  // Display first list

    // ============================================================================
    // SECOND LIST CREATION
    // ============================================================================
    
    cout<< "Please enter how long is the list two is: ";
    cin>> length2;
    
    // Validate second list length (considering merge capacity)
    while(length2 > MAX_ITEM-length1)
    {
        cout<< "The amount you have entered is above "<< MAX_ITEM-length1<<endl;
        cout<< "Please enter a new amount for how long List Two is: "<<endl;
        cin >> length2;
    }
    
    // Build second list with user input
    for(int b = 0; b< length2; b++)
    {
        cout<< "Insert the number for position "<< b +1<< ":"<< endl;
        cin>> space2;
        item2.Initialize(space2);
        listTwo.InsertItem(item2);  // Insert maintains sorted order
    }
    listTwo.Print();  // Display second list

    // ============================================================================
    // LIST MERGING OPERATION
    // ============================================================================
    
    cout << "Calling to MergeList" << endl;
    MergedList.MergeList(listOne, listTwo);  // Merge two sorted lists
    cout<< "After merging both list together we get a sorted list: "<< endl;
    
    MergedList.Print();  // Display merged result

    cout<< "Have A Good Day!"<<endl;

    return 0;
}