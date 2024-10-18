#include "SortedListByArray.h"
#include <iostream> 
#include <string>

using namespace std; 

int main()
{
    SortedListByArray listOne, listTwo, MergedList; 
    ItemType item1, item2;
    int length1, length2;
    int space1, space2;

    cout<< "Please enter how long the List one is (maximum length "<< MAX_ITEM<< "): ";
    cin >> length1;
    while(length1 > MAX_ITEM)
    {
        cout<< "The amount you have entered is above "<< MAX_ITEM<<endl;
        cout<< "Please enter a new amount for how long List One is: "<<endl;
        cin >> length1;
    }
    for(int a = 0; a <length1; a++)
    {
        cout<<"Insert the number for position "<< a + 1<< ":" << endl;
        cin>> space1;
        item1.Initialize(space1);
        listOne.InsertItem(item1);
    }
    listOne.Print();

    cout<< "Please enter how long is the list two is: ";
    cin>> length2;
     while(length2 > MAX_ITEM)
    {
        cout<< "The amount you have entered is above "<< MAX_ITEM<<endl;
        cout<< "Please enter a new amount for how long List Two is: "<<endl;
        cin >> length2;

    }
    for(int b = 0; b< length2; b++)
    {
        cout<< "Insert the number for position "<< b +1<< ":"<< endl;
        cin>> space2;
        item2.Initialize(space2);
        listTwo.InsertItem(item2);
    }
    listTwo.Print(); 
    cout << "Calling to MergeList" << endl;
    MergedList.MergeList(listOne, listTwo);
    cout<< "After merging both list together we get a sorted list: "<< endl;
    
    MergedList.Print();

    cout<< "Have A Good Day!"<<endl;

    return 0;
}