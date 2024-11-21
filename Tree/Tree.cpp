/********************************************************
 * File : Tree.cpp
 * Description : Impelementation file of Tree class
 ********************************************************/

#include "Tree.h"
#include <new>

Tree::Tree()
{
   root = NULL;
}

Tree::Tree(const Tree& originalTree)
{
   CopyTree(root, originalTree.root);
}

void Tree::operator=(const Tree& originalTree)
{
    if (&originalTree == this)
       return;

    Destroy(root);
    CopyTree(root, originalTree.root);
}


void Tree::CopyTree(TreeNode *&copy, const TreeNode* originalTree)
{

    if (originalTree == NULL)
        copy = NULL;
    else
    {
      copy = new TreeNode;
      copy->info = originalTree->info;
      CopyTree(copy->left, originalTree->left);
      CopyTree(copy->right, originalTree->right);
    }
}


Tree::~Tree()
{
   MakeEmpty();  
}

void Tree::Destroy(TreeNode *& tree)
{
   if (tree!= NULL)
   {
     Destroy(tree->left);
     Destroy(tree->right);
     delete tree;
   } 
}

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
      node->left->info.Print();
      cout << "Right:"; 
      node->right->info.Print();
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
