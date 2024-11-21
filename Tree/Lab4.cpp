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
    
    // Print the tree 
    tree.Print();


    return 0;
}