#include <iostream>
#include "ItemType.h"
#include "Tree.h"

int main()
{
    Tree tree;
    ItemType item;

    // Insert items in the tree
    char letters[6] = {'F','N','R','D','G','C'};
    for (int i=0; i<6; i++)
    {
        cout << "Inserting the following Item: " << letters[i] << endl;
        item.Initialize(letters[i]);
        tree.InsertItem(item);
    }
    
    // Print the tree (in-order)
    tree.Print();

    // Count the leaves in the tree
    cout << "The tree has " << tree.GetLength() << " elements" << endl;

    // Test ancestors
    cout << "Test Ancestors for: " << letters[5] << endl;
    item.Initialize(letters[5]);
    tree.Ancestors(item);

    // Test descendants
    cout << "Test Descendants for: " << letters[1] << endl;
    item.Initialize(letters[1]);
    tree.Descendants(item);

    // Test Swap
    Tree newTree;
    tree.Swap(newTree);
    newTree.Print();

    // Test LeafCount()
    cout << "Test LeafCount()" << endl;
    cout << "There are " << tree.LeafCount() << " leaf nodes" << endl;

    return 0;
}