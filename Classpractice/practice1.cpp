int linearSearch (const in arrayOne[], int numOfValues, int key) 
{
    int index = -1; //assume not found 
    for (int i =0; i <numOfvalues; i++)
    {
        //check whether this element is the key value
        if(arrayOne[i]==key)
        {
            index =i;
            break;// - if there are duplicates 
        }
    }
    return index;
}

int main()
{
    int size =5; 
    int a[size]= {0,1,2,3,4}
    int key =1;
    int indexFound = linearSearch(a,size,key);
    if(indexFound!= -1)
    {
        cout <<"Found at "<< indexFound<<endl;
    }
    else
    {
        cout<<"not found"<<endl;
    }
    return 0;
}

