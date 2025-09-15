/*******************************************************************************
 * File: Tree.cpp
 * Author: Maia Munich
 * Course: CISC 2200
 * Description: Implementation of Tree class - A comprehensive Binary Search
 *              Tree (BST) data structure with advanced operations including
 *              traversal, analysis, and tree manipulation.
 * 
 * Algorithm Details:
 * - Binary Search Tree property maintenance
 * - Recursive tree operations for efficiency
 * - In-order traversal for sorted output
 * - Advanced tree analysis (leaves, ancestors, descendants)
 * - Tree mirroring/swapping functionality
 * 
 * Time Complexity:
 * - Insert/Search/Delete: O(log n) average, O(n) worst case
 * - Traversal: O(n) - visits every node once
 * - Tree Analysis: O(n) - examines all nodes
 *******************************************************************************/

/********************************************************
 * File : Tree.cpp
 * Description : Impelementation file of Tree class
 ********************************************************/

#include "Tree.h"
#include <new>

// Default Constructor: Initializes empty tree
// Pre: None
// Post: Tree is initialized with root = NULL
Tree::Tree()
{
   root = NULL;
}

// Copy Constructor: Creates deep copy of existing tree
// Pre: originalTree is a valid Tree object
// Post: New tree is created with identical structure and data
Tree::Tree(const Tree& originalTree)
{
   CopyTree(root, originalTree.root);
}

// Assignment Operator: Assigns one tree to another
// Pre: Both trees are valid Tree objects
// Post: Current tree is replaced with copy of originalTree
void Tree::operator=(const Tree& originalTree)
{
    if (&originalTree == this)  // Self-assignment check
       return;

    Destroy(root);  // Clean up existing tree
    CopyTree(root, originalTree.root);  // Create deep copy
}


// CopyTree: Recursively creates deep copy of tree structure
// Pre: originalTree is valid (may be NULL)
// Post: copy contains identical tree structure
void Tree::CopyTree(TreeNode *&copy, const TreeNode* originalTree)
{

    if (originalTree == NULL)
        copy = NULL;  // Base case: empty subtree
    else
    {
        // Create new node and copy data
        copy = new TreeNode;
        copy->info = originalTree->info;
        
        // Recursively copy left and right subtrees
        CopyTree(copy->left, originalTree->left);
        CopyTree(copy->right, originalTree->right);
    }
}

// Destructor: Cleans up all dynamically allocated memory
// Pre: Tree object is being destroyed
// Post: All nodes are deallocated
Tree::~Tree()
{
   MakeEmpty();  
}

// Destroy: Recursively deallocates all nodes in tree
// Pre: tree is valid (may be NULL)
// Post: All nodes are deallocated, tree becomes NULL
void Tree::Destroy(TreeNode *& tree)
{
   if (tree != NULL)
   {
     Destroy(tree->left);   // Destroy left subtree
     Destroy(tree->right);  // Destroy right subtree
     delete tree;           // Delete current node
   } 
}

// MakeEmpty: Removes all nodes from tree
// Pre: Tree has been initialized
// Post: Tree is empty (root = NULL)
void Tree::MakeEmpty()
{
   Destroy(root);
   root = NULL;
}



bool Tree::IsFull() const
{

  TreeNode * location;
  try{
     location = new TreeNode;
     delete location;
     return false;
  }catch( std::bad_alloc e){
    return true;
  }
}


bool Tree::IsEmpty() const
{
   return root == NULL;

}

int Tree::GetLength() const
{
    return Count(root);    
}

int Tree::Count(TreeNode * tree) const
{
   if (tree == NULL)
       return 0;
   else
       return Count(tree->left) + Count(tree->right) +1;
}



void Tree::RetrieveItem(ItemType & item, bool & found) const
{
    Retrieve(root, item, found);
}


void Tree::Retrieve(TreeNode* tree, 
              ItemType& item, bool& found) const
{
  if (tree == NULL)   found = false;                     

  else if (item.ComparedTo(tree->info) == LESS)      
    Retrieve(tree->left, item, found);
  else if (item.ComparedTo(tree->info) == GREATER)
    Retrieve(tree->right, item, found);
  else
  {
    item = tree->info;
    found = true;
  }
}   


void Tree::InsertItem(ItemType item)
{
   Insert(root, item);
}

void Tree::Insert(TreeNode* & tree, ItemType item)
{
  if (tree == NULL)
  { // Insertion place found.
    tree = new TreeNode;
    tree->right = NULL;
    tree->left = NULL;
    tree->info = item;
  }
  else if (item.ComparedTo(tree->info) == LESS)
    Insert(tree->left, item);    
  else 
    Insert(tree->right, item);   
} 


void Tree::DeleteItem(ItemType item)
{
    Delete(root, item);
}


// first, find which node should be deleted.
void Tree::Delete(TreeNode*& tree, ItemType item)
{
  if (item.ComparedTo(tree->info) == LESS)
     Delete(tree->left, item);   
  else if (item.ComparedTo(tree->info) == GREATER)
     Delete(tree->right, item);  
  else
     DeleteNode(tree);  // Node found
} 

void Tree::DeleteNode(TreeNode*&  tree) {

       ItemType data;
       TreeNode* tempPtr;

        tempPtr = tree;

        if ( tree->left == NULL) {
              tree = tree->right;
              delete tempPtr; 
       } else if (tree->right == NULL){
              tree = tree->left;
              delete tempPtr;
       }else{
              GetPredecessor(tree->left, data);
               tree->info = data;
               Delete(tree->left, data);
        }
} 

void Tree::GetPredecessor( TreeNode* tree,
                               ItemType& data)
{
  while (tree->right != NULL)
    tree = tree->right;
  data = tree->info;
}

void Tree::Print(ofstream & output) const
{
   PrintTree(root, output);
}

void Tree::Print() const
{
   std::cout<<"Binary Search Tree: (in-order)"<<endl;
   PrintTree(root, std::cout);
   std::cout<<endl;
}

void Tree::PrintTree(TreeNode* tree, ostream& output) const
{
  
  if (tree != NULL)
  {
    PrintTree(tree->left, output);   
    output <<tree->info<<"  ";
    PrintTree(tree->right, output);  
  }
}


/* New functions*/
int Tree::LeafCount() const
{
  return NumLeaves(root);
}

int Tree::NumLeaves(TreeNode * node) const
{
  if (node == NULL)
  {
    return 0;
  }
  if ((node->left == NULL) && (node->right == NULL))
  {
    return 1;
  }
  return (NumLeaves(node->left) + NumLeaves(node->right));
}
   
void Tree::Ancestors(ItemType item) const
{
  bool is_found;
  RetrieveItem(item, is_found);
  if (!is_found)
  {
    cout << "Item not found on the Tree" << endl;
  }
  else
  {
    GetAncestors(root, item);
  }
}

void Tree::GetAncestors(TreeNode* node, ItemType item) const
{
  if (node != NULL)
  {
    if (item.ComparedTo(node->info)== LESS)
    {
      node->info.Print();
      GetAncestors(node->left, item);
    }
    else if (item.ComparedTo(node->info)== GREATER)
    {
      node->info.Print();
      GetAncestors(node->right, item);
    }
  }
}

void Tree::Descendants(ItemType item) const
{
  bool is_found;
  RetrieveItem(item, is_found);
  if (!is_found)
  {
    cout << "Item not found on the Tree" << endl;
  }
  else
  {
    GetDescendants(root, item);
  }
}

void Tree::GetDescendants(TreeNode* node, ItemType item) const
{
  if (node != NULL)
  {
    if (item.ComparedTo(node->info)== LESS)
    {
      GetDescendants(node->left, item);
    }
    else if (item.ComparedTo(node->info)== GREATER)
    {
      GetDescendants(node->right, item);
    }
    else  
    {
      cout << "Left:";
      if (node->left != NULL)
      {
        node->left->info.Print();
      }
      cout << "Right:"; 
      if (node->left != NULL)
      {
        node->right->info.Print();
      }
    }
  }
}

void Tree::Swap(Tree & newTree)
{
  SwapNode(root, newTree.root);
}

void Tree::SwapNode(TreeNode * node, TreeNode * &newNode) 
{
  if (node ==  NULL)
  {
    newNode = NULL;
  }
  else
  {
    newNode = new TreeNode;
    newNode->info = node->info;
    SwapNode(node->left, newNode->right);
    SwapNode(node->right, newNode->left);
  }
}
