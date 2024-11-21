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


class TreeNode{

public:
   ItemType info;
   TreeNode * left;
   TreeNode * right;   
}; 

class Tree
{
public:
   Tree();
   ~Tree();
 
   Tree(const Tree & originalTree); //copy constructor
   void operator=(const Tree & originalTree);

   void MakeEmpty();

   bool IsEmpty() const;
   bool IsFull() const;

   int GetLength() const;  //how many nodes in the tree

   void RetrieveItem( ItemType & item, bool & found) const;
   void InsertItem ( ItemType  item);
   void DeleteItem ( ItemType  item);

   void Print(ofstream & output) const;
   void Print() const;

   /* New functions*/
   int LeafCount() const;
   void Ancestors(ItemType item) const;
   void Descendants(ItemType item) const;
   void Swap(Tree & newTree);

private:

   TreeNode * root;

   void Destroy(TreeNode *& tree);
   void CopyTree(TreeNode *& copy, const TreeNode * originalTree);

   int Count(TreeNode * tree) const;
   void Retrieve(TreeNode * tree, ItemType & item, bool &found) const;
   void Insert(TreeNode *& tree, ItemType item);
  
   void Delete(TreeNode *& tree, ItemType item);
   void DeleteNode(TreeNode *& tree);
   void GetPredecessor (TreeNode * tree, ItemType & item);
   void PrintTree(TreeNode * tree, ostream& output) const;

};

#endif