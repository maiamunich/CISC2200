/*******************************************************************************
 * File: UnsortedListbyArray.h
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Header file for UnsortedListByArray class - An unsorted list
 *              implementation using array-based storage with student data
 *              management and list splitting functionality.
 * 
 * Features:
 * - Array-based unsorted list storage
 * - Student data management with FIDN, first name, last name
 * - Duplicate prevention for student records
 * - List splitting based on key values
 * - Linear search for item retrieval
 * - Iterator support for sequential access
 * 
 * Data Structure: Dynamic array with unsorted order
 * Algorithms: Linear search, list splitting, duplicate checking
 *******************************************************************************/

// SPECIFICATION FILE		( UnsortedType.h )
#ifndef UNSORTEDLISTBYARRAY_H
#define UNSORTEDLISTBYARRAY_H

#include "ItemType.h"

// UnsortedListByArray class: Maintains an unsorted list using array implementation
// Designed for student data management with duplicate prevention
class UnsortedListByArray	
{				
public : 			

    // Constructor
    UnsortedListByArray();

    // Basic List Operations
    void MakeEmpty( );                    // Empties the list
    void InsertItem( ItemType  item );   // Inserts item at end of list
    void DeleteItem( ItemType  item );   // Removes specified item

    // Advanced Operations
    bool NewInsertItem (ItemType newItem); // Inserts item with duplicate checking
    void SplitList (ItemType item, UnsortedListByArray & listOne, UnsortedListByArray & listTwo); // Splits list based on key
    void Print ();                        // Displays all items in list

    // List State Queries
    bool IsFull( ) const;                // Checks if list is at capacity
    bool IsEmpty( ) const;               // Checks if list is empty
    int  GetLength( ) const;             // Returns current number of items

    // Search and Retrieval
    void RetrieveItem( ItemType &  item, bool&  found ); // Linear search for item

    // Iterator Operations
    void ResetList( );                   // Resets iterator to beginning
    void GetNextItem( ItemType&  item ); // Gets next item in sequence

protected :
    int length;                          // Current number of items in list
    ItemType info[MAX_ITEM];             // Array storing the items
    int currentPos;                      // Current position for iterator
};


#endif
