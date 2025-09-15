/*******************************************************************************
 * File: practice1.cpp
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Practice program demonstrating linear search algorithm
 *              implementation with array processing and key value searching.
 * 
 * Algorithm:
 * - Linear search through array elements
 * - Sequential comparison with target key
 * - Returns index of found element or -1 if not found
 * - Handles duplicate values by returning first occurrence
 * 
 * Time Complexity: O(n) - worst case examines all elements
 * Space Complexity: O(1) - constant extra space
 *******************************************************************************/

#include <iostream>
using namespace std;

// linearSearch: Performs linear search for key value in array
// Pre: arrayOne is valid array, numOfValues is array size, key is search target
// Post: Returns index of key if found, -1 if not found
// Algorithm: Sequential search through array elements
int linearSearch (const int arrayOne[], int numOfValues, int key) 
{
    int index = -1; // Initialize to "not found" state
    
    // Search through array elements sequentially
    for (int i = 0; i < numOfValues; i++)
    {
        // Check if current element matches the key
        if(arrayOne[i] == key)
        {
            index = i;  // Store index of found element
            break;      // Exit loop (handles duplicates by returning first occurrence)
        }
    }
    return index;  // Return index or -1 if not found
}

// Main function: Demonstrates linear search with test data
int main()
{
    int size = 5; 
    int a[size] = {0, 1, 2, 3, 4};  // Test array
    int key = 1;                    // Search target
    
    // Perform linear search
    int indexFound = linearSearch(a, size, key);
    
    // Display search results
    if(indexFound != -1)
    {
        cout << "Found at " << indexFound << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
    return 0;
}

