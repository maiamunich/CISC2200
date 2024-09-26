//  SPECIFICATION FILE ItemType.h 
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
#include "Student.h"
using namespace std;

const int  MAX_ITEM = 6;
enum  RelationType { LESS, EQUAL, GREATER };

class  ItemType	: public Student	// declares class data type
{						
public : 			// 4 public member functions

  ItemType() {}

  RelationType ComparedTo( ItemType  otherItem ) const 
  {						
    if ( value  <  otherItem.value )
       return  LESS;
    else if ( value  > otherItem.value )
       return  GREATER;
    else  return  EQUAL;
  }

  void Print( ) const 
  {
   cout  <<  getFIDN() << ": ,"<< getFN()<< " ,"<< getLN()  <<  endl;
  }

   void Initialize(string FIDN)
  {
    this->value  = FIDN;
    setFIDN(FIDN);              
  } 	           


private :			// 1 private data member
	string value;
   		// could be any type 
} ;
#endif	
