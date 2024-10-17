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

    cout<< "Please enter how long the list one is: ";
    cin >> length1;
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
    for(int b = 0; b< length2; b++)
    {
        cout<< "Insert the number for position"<< b +1<< ":"<< endl;
        cin>> space2;
        item2.Initialize(space2);
        listTwo.InsertItem(item2);
        cout<<"outputted";
    }
    cout<<"yessss bitchh"<<endl;
    listTwo.Print(); 



    //sorting the lists one 
  //  for(int i = 0; i < listOne.GetLength(); i++)
    //{
      //  for (int j = 0; j < listOne.GetLength(); j++)
        //{
          ///  if(array[j] > array[i + 1])
  //          {
    //            int temp = array[j];
      //          array[j] = array[j + 1];
        //        array[j + 1] = temp;
          //  }
       // }
   // }
    //sorting the list two 
 /*    for(int z = 0; z < listTwo.GetLength(); z++)
    {
        for (int y = 0; y < listTwo.GetLength(); y++)
        {
            if(array[y] > array[z + 1])
            {
                int temp = array[y];
                array[y] = array[y + 1];
                array[y + 1] = temp;
            }
        }
    }
*/
/*
    cout<< "The outcome of your inserted number comes out too these two list: "<< endl;
    listOne.Print();

    cout<<endl;

    listTwo.Print();

*/
    MergedList.MergeList(listOne, listTwo);
    cout<< "After merging both list together we get a sorted list: "<< endl;
    
    MergedList.Print();

    cout<< "Have A Good Day!"<<endl;

    return 0;
}