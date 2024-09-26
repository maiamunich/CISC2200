#include "ItemType.h"
#include "UnsortedListbyArray.h"

void PrintList( UnsortedListByArray& list)
// Pre:  list has been initialized.         
// Post: Each component in list has been written. 
// 
{
  int length;
  ItemType item;

  list.ResetList( );
  length = list.GetLength( );
  for (int counter = 1; counter <= length; counter++)
  {
    list.GetNextItem(item);
    item.Print( );
  }
}

int main(){

    UnsortedListByArray listOne;

    ItemType x;
    x.Initialize(5);
    listOne.InsertItem(x);

    ItemType y;
    y.Initialize(6);
    listOne.InsertItem(y);

    PrintList(listOne);

    listOne.MakeEmpty();
    if (listOne.IsEmpty())
    {
        cout<<"List one is Empty."<<endl;
    }
    return 0;
}
