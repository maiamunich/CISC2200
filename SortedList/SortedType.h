#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include "ItemType.h"


struct NodeType {
     ItemType info;
     NodeType * next;
};


class  SortedType		// declares a class data type
{				
public : 			
  SortedType();
  ~SortedType();
  void MakeEmpty( );        // 8 public member functions
  bool IsFull( ) const;
  bool IsEmpty( ) const;              
  int  GetLength( ) const;  // returns length of list
  void RetrieveItem( ItemType&  item, bool&  found );
  void InsertItem( ItemType item ); 	
  void DeleteItem( ItemType  item ); 	
  void ResetList( );
  void GetNextItem( ItemType & item ); 	
private:		
  NodeType* listData;
  int length;
  NodeType* currentPos;
};	


#endif