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
    cout << "Test Ancestors for: C" << endl;
    item.Initialize('C');
    tree.Ancestors(item);

    // Test descendants
    cout << "Test Descendants for: N" << endl;
    item.Initialize('N');
    tree.Descendants(item);

    // Test Swap
    Tree newTree;
    tree.Swap(newTree);
    newTree.Print();

    // Test LeafCount()
    cout << "There are " << tree.LeafCount() << " leaf nodes" << endl;

    return 0;
}