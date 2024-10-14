#include "SortedType.h"

//constructor

SortedType::SortedType()
{
  length=0;
  listData = NULL;
}

//destructor

SortedType::~SortedType()
{
  MakeEmpty();
}


int SortedType::GetLength() const
{
  return length;
} 


bool SortedType::IsFull() const
{
  NodeType* location;
  try
  {
    location = new NodeType;
    delete location;
    return false;
  }
  catch (std::bad_alloc e)
  {
    return true;
  }
}

bool SortedType::IsEmpty() const
{
   return (listData== NULL)? true: false;

}


void SortedType::MakeEmpty() 
{
  NodeType *tempPtr;
  while (listData != NULL)
  {
    tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
  }
  length = 0;
  listData = NULL;
}

// Pre: list is not full and item is not in list.
// Post: item is in the list; length has been incremented.

void SortedType::InsertItem ( ItemType  item ) 
{ 
  //find the location  
  NodeType * location;
  NodeType * preLoc;

  location = listData;
  preLoc = NULL;
  bool moreToSearch = (location != NULL);

  while (moreToSearch)
  {
      if (item.ComparedTo(location->info) == GREATER)
      {  
          preLoc = location;
          location = location->next;
          moreToSearch = (location != NULL);          
      }else //pass the location
          moreToSearch = false;          
  }
  
  // obtain and fill a node
  NodeType * newNode = new NodeType;
  newNode->info = item;
  
  //insert node into list
  if (preLoc == NULL) //the first node
  {
      newNode ->next = listData;
      listData = newNode;
  }else{
      newNode ->next = location;
      preLoc->next = newNode;
  }

  length++;
}

// Pre: Key member of item is initialized.
// Post: If found, item’s key matches an element’s key in the list and a copy of that
// element has been stored in item; otherwise, item is unchanged.

void  SortedType::RetrieveItem( ItemType&  item, bool&  found )  
{  
  
   NodeType*  location = listData;
    bool  moreToSearch = ( location != NULL);

   found = false ;
	
   while ( moreToSearch  &&  !found ) 
   {  
          if ( item.ComparedTo(location->info ) == EQUAL)             // match here
          { 
                found = true;
   	        item  = location->info;
	  }
	  else if (item.ComparedTo(location->info) == GREATER)	    // advance pointer 
	  { 
               location = location->next;  
               moreToSearch = ( location  !=  NULL );
          }else
               moreToSearch = false;   
   }     
}


//pre: item's key has been initialized. An element in the list has a key that matches item's
//Post: no element in the list has a key that matches item's

void SortedType::DeleteItem(ItemType item)
{
NodeType* location = listData;
NodeType* tempLocation;
// Find the item
if (item.ComparedTo(listData->info) == EQUAL) 
{ // item in first location
  tempLocation = location;
  listData = listData->next; //move the head of the list
}
else{ 
  while (item.ComparedTo((location->next)->info) != EQUAL)
    location = location->next;
  tempLocation = location->next;
  location->next = (location ->next)->next;
  //remove the middle one, connect the two ends
}
delete tempLocation;
length--;


}



void SortedType::ResetList()
{ 
  currentPos = NULL;
}

//Pre: the item at the current position is not the last in the list
//Post: current position has been updated. Item is current item. Does not check for running off the end of the lsit

void SortedType::GetNextItem(ItemType& item)
{
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;

  item = currentPos->info;
}
