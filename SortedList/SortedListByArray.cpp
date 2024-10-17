#include "SortedListByArray.h"

SortedListByArray::SortedListByArray()
{
  length = 0;
}


bool SortedListByArray::IsFull() const
{
  return (length == MAX_ITEM);
}

int SortedListByArray::GetLength( ) const
{
  return length;
}


bool SortedListByArray::IsEmpty() const
{
  return (length == 0);
}

void SortedListByArray::InsertItem(ItemType item) 
{
   bool moreToSearch; 
   int location = 0;
   moreToSearch = (location < length);
   while (moreToSearch)
   {
      switch(item.ComparedTo(info[location]))
      {
         case LESS : moreToSearch = false; break;
         case GREATER : location++;
                        moreToSearch = (location < length);
                        break;
      }
   }

   for ( int index = length; index > location; index--)
        info[index] = info[index-1];

   info[location] = item;
   length++;
}


void SortedListByArray::RetrieveItem(ItemType& item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged. 
{
  int midPoint;
  int first =0;
  int last = length -1;
  
  bool moreToSearch = (first <= last);
  found = false;
  while (moreToSearch && !found) 
  {
    midPoint = (first+last)/2;
    switch (item.ComparedTo(info[midPoint]))
    { 
      case LESS    : last = midPoint -1;
                     moreToSearch = (first <= last);
                     break;
      case GREATER : first = midPoint +1;
                     moreToSearch = (first <= last);
                     break;
      case EQUAL   : found = true;
                     item = info[midPoint];
                     break;
    }
  }
}


void SortedListByArray::DeleteItem(ItemType item) 
// Pre: item�s key has been inititalized.
//	One and only one element in the list has a key that matches item�s.
// Post: No element in the list has a key that matches item�s.
{
   int location = 0;
   while(item.ComparedTo(info[location])!= EQUAL)
       location++;

   for ( int index = location +1; index < length; index++)
        info[index-1] = info[index];
   
   length--;
}


void SortedListByArray::MakeEmpty()
// Pre:  N/A   
// Post: the list is empty
{
   length = 0;
}



void SortedListByArray::ResetList ( )  
// Pre:  List has been inititalized.
// Post: Current position is prior to first element.
{    
  currentPos  =  -1 ;
}


void SortedListByArray::GetNextItem ( ItemType&  item )  
// Pre:  List has been initialized. Current position is 
//       defined. 
//       Element at current position is not last in list.
// Post: Current position is updated to next position.
// 	  item is a copy of element at current position.
{
  currentPos++  ;
  item = info [currentPos] ;
}

  void SortedListByArray::MergeList(SortedListByArray& listOne, SortedListByArray& listTwo)
  // Pre: The SortedList Object has been initialized and empty.
  //      listOne and listTwo have been initialized and not empty
  //Post: List contains all items from listOne and listTwo.
  {
    this->MakeEmpty();
    if( !listOne.IsEmpty() && !listTwo.IsEmpty())
    {
      ItemType item1, item2;
      //resetting list to beginning location
      listOne.ResetList();
      listTwo.ResetList();
      //this->ResetList();

      //creating 2 new variables for the current positions of list one and two
      int currentPos1 = 0;
      int currentPos2 = 0;
     //getting the first element in the list
      listOne.GetNextItem(item1);//Does this make it go to the end or does it keep on going without knowing if it is done
      listTwo.GetNextItem(item2);
      while (currentPos1 <= listOne.GetLength() && currentPos2 <= listTwo.GetLength())
      {
        item1.Print();
         item2.Print();
         if(item1.ComparedTo(item2)==LESS || item1.ComparedTo(item2)== EQUAL)
          {
           this->InsertItem(item1);
           currentPos1++;
           if(currentPos1 < listOne.GetLength())
           {
              listOne.GetNextItem(item1);
            }
           }
           else 
          {

            this->InsertItem(item2);
            currentPos2++;
            if(currentPos2 < listTwo.GetLength())
            {
             listTwo.GetNextItem(item2);
            }
         }
      }
    
    //makes sure that the code is checking which list has been completed and finishing the other one
      while(currentPos1 < listOne.GetLength())
      {
        this->InsertItem(item1);
        currentPos1++;
        if(currentPos1 < listOne.GetLength())
        {
          listOne.GetNextItem(item1);
        }
      } 
      while(currentPos2 < listTwo.GetLength())
      {
         this->InsertItem(item2);
        currentPos2++;
        if(currentPos2 < listTwo.GetLength())
        {
           listTwo.GetNextItem(item2);
        } 
      }
    
    }
    else
    {
      cout<< " One or Both lists are empty, nothing to merge"<<endl;
    }
    cout<<"Merge complete. Merge list thength:"<<length<<endl; 
  }


void SortedListByArray::Print()
{
  for(int i=0; i< length; i++)
  {
    info[i].Print();
    
  }
}

  void SortedListByArray::BubbleArraySort()
  {
    for(int z = 0; z < length; z++)
    {
        for (int y = 0; y < length; y++)
        {
            if(info[y].ComparedTo (info[z + 1])== GREATER)
            {
                ItemType temp = info[y];
                info[y] = info[y + 1];
                info[y + 1] = temp;
            }
        }
    }
  }
