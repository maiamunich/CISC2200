#include <iostream>
#include "ItemType.h"
#include "Tree.h"

int main()
{
    Tree tree;
    ItemType item;

    cout << "Testing as in typescript.pdf" << endl;
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

    cout << "End testing as in typescript.pdf" << endl;

    cout << "Testing other conditions" << endl;

    // Test ancestors and descendants of letters not in the tree
    char test = 'A';
    item.Initialize(test);

    // Test ancestors
    cout << "Test Ancestors for: " << test << endl;
    tree.Ancestors(item);

    // Test descendants
    cout << "Test Descendants for: " << test << endl;
    tree.Descendants(item);

    return 0;
}