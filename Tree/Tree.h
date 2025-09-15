/*******************************************************************************
 * File: Tree.h
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Header file for Tree class - A comprehensive implementation
 *              of a Binary Search Tree (BST) data structure with advanced
 *              operations including traversal, analysis, and tree manipulation.
 * 
 * Features:
 * - Binary Search Tree operations (insert, delete, search)
 * - In-order traversal and printing
 * - Tree analysis (leaf counting, ancestor/descendant finding)
 * - Tree manipulation (swapping/mirroring)
 * - Memory management with proper cleanup
 * - Copy constructor and assignment operator
 * 
 * Data Structure: Binary Search Tree with TreeNode structure
 * Algorithms: Recursive BST operations, in-order traversal
 *******************************************************************************/

/***********************************************
 * File : Tree.h
 * Date : 10/10/08
 * Description : Header file of Class TreeType 
 *               A binary search tree
 **********************************************/
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <fstream>
using namespace std;

#include <queue>

#include "ItemType.h"


// TreeNode class: Represents a node in the binary search tree
// Contains data and pointers to left and right child nodes
class TreeNode{
public:
    ItemType info;      // Data stored in the node
    TreeNode *left;     // Pointer to left child (smaller values)
    TreeNode *right;    // Pointer to right child (larger values)
}; 

// Tree class: Main Binary Search Tree data structure
// Implements all BST operations with advanced tree analysis capabilities
class Tree
{
public:
    // Constructors and Destructor
    Tree();                                    // Default constructor
    ~Tree();                                   // Destructor with memory cleanup
    
    // Copy Constructor and Assignment Operator
    Tree(const Tree & originalTree);          // Copy constructor
    void operator=(const Tree & originalTree); // Assignment operator

    // Basic Tree Operations
    void MakeEmpty();                          // Removes all nodes from tree
    bool IsEmpty() const;                      // Checks if tree is empty
    bool IsFull() const;                       // Checks if tree is at capacity
    int GetLength() const;                     // Returns number of nodes in tree

    // BST Operations
    void RetrieveItem(ItemType & item, bool & found) const; // Searches for item
    void InsertItem(ItemType item);            // Inserts new item maintaining BST property
    void DeleteItem(ItemType item);            // Removes item from tree

    // Tree Display and Output
    void Print(ofstream & output) const;        // Prints tree to file (in-order)
    void Print() const;                         // Prints tree to console (in-order)

    // Advanced Tree Analysis
    int LeafCount() const;                     // Counts leaf nodes in tree
    void Ancestors(ItemType item) const;       // Prints all ancestors of given item
    void Descendants(ItemType item) const;     // Prints all descendants of given item
    void Swap(Tree & newTree);                 // Creates mirrored version of tree

private:
    // Data Members
    TreeNode *root;                            // Pointer to root of the tree

    // Memory Management Helpers
    void Destroy(TreeNode *& tree);            // Recursively destroys tree
    void CopyTree(TreeNode *& copy, const TreeNode * originalTree); // Deep copy helper

    // BST Operation Helpers
    int Count(TreeNode * tree) const;          // Recursively counts nodes
    void Retrieve(TreeNode * tree, ItemType & item, bool &found) const; // Search helper
    void Insert(TreeNode *& tree, ItemType item); // Insert helper
    
    // Deletion Helpers
    void Delete(TreeNode *& tree, ItemType item); // Delete helper
    void DeleteNode(TreeNode *& tree);         // Handles node deletion cases
    void GetPredecessor(TreeNode * tree, ItemType & item); // Finds predecessor
    
    // Display Helpers
    void PrintTree(TreeNode * tree, ostream& output) const; // In-order print helper

    // Advanced Analysis Helpers
    int NumLeaves(TreeNode * node) const;      // Recursively counts leaves
    void GetAncestors(TreeNode* node, ItemType item) const; // Ancestor helper
    void GetDescendants(TreeNode* node, ItemType item) const; // Descendant helper
    void SwapNode(TreeNode * node, TreeNode * &newNode); // Mirror helper
};

#endif