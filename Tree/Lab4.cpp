/*******************************************************************************
 * File: Lab4.cpp
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Comprehensive test program for Tree class demonstrating
 *              Binary Search Tree operations including insertion, deletion,
 *              traversal, and advanced tree analysis functions.
 * 
 * Test Features:
 * - BST construction with character data
 * - In-order traversal demonstration
 * - Tree analysis (leaf counting, ancestors, descendants)
 * - Tree manipulation (swapping/mirroring)
 * - Interactive tree building
 * - Error handling for non-existent items
 * 
 * Test Data: Character-based BST with letters F, N, R, D, G, C
 *******************************************************************************/

#include <iostream>
#include "ItemType.h"
#include "Tree.h"

int main()
{
    // ============================================================================
    // INITIALIZATION
    // ============================================================================
    
    Tree tree;        // Create BST object
    ItemType item;    // Item for operations

    // ============================================================================
    // BASIC BST CONSTRUCTION TEST
    // ============================================================================
    
    cout << "Testing as in typescript.pdf" << endl;
    
    // Insert items in the tree to create a specific BST structure
    char letters[6] = {'F','N','R','D','G','C'};
    for (int i=0; i<6; i++)
    {
        cout << "Inserting the following Item: " << letters[i] << endl;
        item.Initialize(letters[i]);
        tree.InsertItem(item);
    }
    
    // ============================================================================
    // TREE DISPLAY AND ANALYSIS
    // ============================================================================
    
    // Print the tree (in-order traversal shows sorted order)
    tree.Print();

    // Count the nodes in the tree
    cout << "The tree has " << tree.GetLength() << " elements" << endl;

    // ============================================================================
    // ANCESTOR AND DESCENDANT ANALYSIS
    // ============================================================================
    
    // Test ancestors for letter 'C' (should show path from root)
    cout << "Test Ancestors for: " << letters[5] << endl;
    item.Initialize(letters[5]);
    tree.Ancestors(item);

    // Test descendants for letter 'N' (should show subtree)
    cout << "Test Descendants for: " << letters[1] << endl;
    item.Initialize(letters[1]);
    tree.Descendants(item);

    // ============================================================================
    // TREE MANIPULATION TEST
    // ============================================================================
    
    // Test Swap (creates mirrored version of tree)
    Tree newTree;
    tree.Swap(newTree);
    newTree.Print();

    // Test LeafCount (counts leaf nodes)
    cout << "Test LeafCount()" << endl;
    cout << "There are " << tree.LeafCount() << " leaf nodes" << endl;

    cout << "End testing as in typescript.pdf" << endl;

    // ============================================================================
    // ERROR HANDLING TEST
    // ============================================================================
    
    cout << "Testing other conditions" << endl;

    // Test ancestors and descendants of letters not in the tree
    char test = 'A';
    item.Initialize(test);

    // Test ancestors for non-existent item
    cout << "Test Ancestors for: " << test << endl;
    tree.Ancestors(item);

    // Test descendants for non-existent item
    cout << "Test Descendants for: " << test << endl;
    tree.Descendants(item);

    // ============================================================================
    // INTERACTIVE TREE BUILDING
    // ============================================================================
    
    // Testing entering a tree interactively
    int MAX_ITEMS = 10;
    char elements[10];
    int len;
    Tree green;

    cout << "Please enter the number of elements in the tree (maximum length " << MAX_ITEMS << "): ";
    cin >> len;
    while(len > MAX_ITEMS)
    {
        cout<< "The amount you have entered is above "<< MAX_ITEMS << endl;
        cout<< "Please enter a new amount of elements: "<<endl;
        cin >> len;
    }

    // Build tree from user input
    for(int i = 0; i <len; i++)
    {
        cout<<"Insert the letter for position "<< i + 1<< ":" << endl;
        cin >> elements[i];
        item.Initialize(elements[i]);
        green.InsertItem(item);
    }

    // ============================================================================
    // ANALYSIS OF USER-BUILT TREE
    // ============================================================================
    
    // Print the user-built tree (in-order)
    green.Print();

    // Count the nodes
    cout << "The tree has " << green.GetLength() << " elements" << endl;

    // Test ancestors for middle element
    cout << "Test Ancestors for: " << elements[len/2] << endl;
    item.Initialize(elements[len/2]);
    green.Ancestors(item);

    // Test descendants for middle element
    cout << "Test Descendants for: " << elements[len/2] << endl;
    item.Initialize(elements[len/2]);
    green.Descendants(item);

    // Test Swap on user-built tree
    Tree newiTree;
    green.Swap(newiTree);
    cout << "Test flipping the tree" << endl;
    newiTree.Print();

    // Test LeafCount on user-built tree
    cout << "Test LeafCount()" << endl;
    cout << "There are " << green.LeafCount() << " leaf nodes" << endl;

    return 0;
}