/*******************************************************************************
 * File: SortedListByArray.h
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Header file for SortedListByArray class - A sorted list
 *              implementation using array-based storage with automatic
 *              sorting maintenance and advanced list operations.
 * 
 * Features:
 * - Array-based sorted list with automatic ordering
 * - Binary search for efficient retrieval
 * - List merging functionality
 * - Bubble sort implementation
 * - Iterator support for sequential access
 * - Duplicate prevention
 * 
 * Data Structure: Dynamic array with sorted order maintenance
 * Algorithms: Binary search, insertion sort, bubble sort, merge algorithm
 *******************************************************************************/

// SPECIFICATION FILE		( SortedType.h )
#ifndef SORTEDLISTBYARRAY_H
#define SORTEDLISTBYARRAY_H

#include "ItemType.h"

// SortedListByArray class: Maintains a sorted list using array implementation
// Automatically keeps elements in sorted order for efficient operations
class SortedListByArray		
{				
public : 			

    // Constructor
    SortedListByArray();

    // Basic List Operations
    void MakeEmpty( );                    // Empties the list
    void InsertItem( ItemType  item );   // Inserts item in sorted position
    void DeleteItem( ItemType  item );   // Removes specified item

    // List State Queries
    bool IsFull( ) const;                // Checks if list is at capacity
    bool IsEmpty( ) const;               // Checks if list is empty
    int  GetLength( ) const;             // Returns current number of items

    // Search and Retrieval
    void RetrieveItem( ItemType &  item, bool&  found ); // Binary search for item

    // Iterator Operations
    void ResetList( );                   // Resets iterator to beginning
    void GetNextItem( ItemType&  item ); // Gets next item in sequence

    // Advanced Operations
    void MergeList(SortedListByArray& listOne, SortedListByArray& listTwo); // Merges two sorted lists
    void Print();                        // Displays all items in list
    void BubbleArraySort();              // Sorts list using bubble sort algorithm

private :
    int length;                          // Current number of items in list
    ItemType info[MAX_ITEM];             // Array storing the sorted items
    int currentPos;                      // Current position for iterator
};


#endif