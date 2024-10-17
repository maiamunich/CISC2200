#include "SortedListByArray.h"
#include <iostream> 
#include <string>

using namespace std; 

int main()
{
    SortedListByArray item1, item2, listOne, listTwo, MergedList; 
    cout<< "Please enter the numbers for List One: ";
    cin<< listOne.info[item1];

    cout<< "Please enter the numbers for List Two: ";
    cin<< listTwo.info[item2];

    //sorting the lists one 
    for(int i = 0; i < listOne.GetLength(); i++)
    {
        for (int j = 0; j < listOne.GetLength(); j++)
        {
            if(info[j] > info[i + 1])
            {
                int temp = info[j];
                info[j] = info[j + 1];
                info[j + 1] = temp;
            }
        }
    }
    //sorting the list two 
    for(int z = 0; z < listTwo.GetLength(); z++)
    {
        for (int y = 0; y < listTwo.GetLength(); y++)
        {
            if(info[j] > info[z + 1])
            {
                int temp = info[y];
                info[y] = info[y + 1];
                info[y + 1] = temp;
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