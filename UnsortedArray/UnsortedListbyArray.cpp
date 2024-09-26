#include "UnsortedListbyArray.h"

UnsortedListByArray::UnsortedListByArray()
{
  length = 0;
}


bool UnsortedListByArray::IsFull() const
{
  return (length == MAX_ITEM);
}

int UnsortedListByArray::GetLength( ) const
{
  return length;
}


bool UnsortedListByArray::IsEmpty() const
{
  return (length == 0);
}



void UnsortedListByArray::InsertItem(ItemType item)
// Post: item is in the list.
{
  info[length] = item;
  length++;
}



void UnsortedListByArray::RetrieveItem(ItemType& item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged. 
{
  bool moreToSearch;
  int location = 0;
  found = false;
  moreToSearch = (location < length);
  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    { case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
}


void UnsortedListByArray::DeleteItem ( ItemType  item ) 
// Pre: item’s key has been inititalized.
//	One and only one element in the list has a key that matches item’s.
// Post: No element in the list has a key that matches item’s.
{    
  int  location  =  0 ;

  while (item.ComparedTo (info[location])  !=  EQUAL)
         location++;
  // move last element into position where item was located

  info [location] = info [length - 1 ] ;
  length-- ; //the length of the list is decreased
}


void UnsortedListByArray::MakeEmpty()
// Pre:  N/A   
// Post: the list is empty
{
   length = 0;
}



void UnsortedListByArray::ResetList ( )  
// Pre:  List has been inititalized.
// Post: Current position is prior to first element.
{    
  currentPos  =  -1 ;
}


void UnsortedListByArray::GetNextItem ( ItemType&  item )  
// Pre:  List has been initialized. Current position is 
//       defined. 
//       Element at current position is not last in list.
// Post: Current position is updated to next position.
// 	  item is a copy of element at current position.
{
  currentPos++  ;
  item = info [currentPos] ;
}

bool UnsortedListByArray::NewInsertItem (ItemType newItem)
{
    //checking whether the item is in the list
    //use length to figure out for loop 
    for (int i=0; i<length; i++ )
    {
        if(newItem.CompareTo(info[i])==EQUAL)//see what other data type variable is needed)// found return true 
        {
          cout << "List already has item" << endl;
          return false;
        }
        else
        {
            //inster the new item here
            length++; 
            info[length]=newItem;
            cout<<"New Item has been insterted"<<endl;
            return true; 
        }
    }
}
void UnsortedListByArray::SplitList (ItemType item, UnsortedListByArray & listOne, UnsortedListByArray & listT    wo)
{
}
void UnsortedListByArray::Print ()
{
}
