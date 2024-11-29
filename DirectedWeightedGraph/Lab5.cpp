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

    for(int i = 0; i <len; i++)
    {
        cout<<"Insert the letter for position "<< i + 1<< ":" << endl;
        cin >> elements[i];
        item.Initialize(elements[i]);
        green.InsertItem(item);
    }

    // Print the tree (in-order)
    green.Print();

    // Count the leaves in the tree
    cout << "The tree has " << green.GetLength() << " elements" << endl;

    // Test ancestors
    cout << "Test Ancestors for: " << elements[len/2] << endl;
    item.Initialize(elements[len/2]);
    green.Ancestors(item);

    // Test descendants
    cout << "Test Descendants for: " << elements[len/2] << endl;
    item.Initialize(elements[len/2]);
    green.Descendants(item);

    // Test Swap
    Tree newiTree;
    green.Swap(newiTree);
    cout << "Test flipping the tree" << endl;
    newiTree.Print();

    // Test LeafCount()
    cout << "Test LeafCount()" << endl;
    cout << "There are " << green.LeafCount() << " leaf nodes" << endl;

    return 0;
}