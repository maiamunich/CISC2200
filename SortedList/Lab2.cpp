#include "SortedListByArray.h"
#include <iostream> 
#include <string>

using namespace std; 

int main()
{
    SortedListByArray item1, item2, listOne, listTwo, MergedList; 
    int array[MAX_ITEM];

    cout<< "Please enter the numbers for List One: ";
    cin<< listOne.info[item1];

    cout<< "Please enter the numbers for List Two: ";
    cin<< listTwo.info[item2];

    //sorting the lists one 
    for(int i = 0; i < listOne.GetLength(); i++)
    {
        for (int j = 0; j < listOne.GetLength(); j++)
        {
            if(array[j] > array[i + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    //sorting the list two 
    for(int z = 0; z < listTwo.GetLength(); z++)
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


    cout<< "The outcome of your inserted number comes out too these two list: "<< endl;
    listOne.Print();

    cout<<endl;

    listTwo.Print();

    MergedList.MergeList(listOne, listTwo);

    cout<< "After merging both list together we get a sorted list: "<< endl;
    
    MergedList.Print();

    cout<< "Have A Good Day!"<<endl;

    return 0;
}