//Problem : You have been given an integer arraylist 'ARR' of size 'N'. It contains only 0s,1s and 2s.Write a solution to sort this arraylist.
//Condition : Try to solve this problem in 'single scan' ,'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just case.
#include<iostream>
using namespace std;

int sort012(int a[],int size)
{
    int lo=0,hi=size-1,mid=0;
    while (mid<=hi)
    {
       switch (a[mid])
       {
       case 0:
           swap(a[lo++],a[mid++]);
           break;
       
       case 1:
           mid++;
           break;
       
       case 2:
           swap(a[hi--],a[mid++]);
           break;
       
              }
    }
    
}
int main()
{
    int a[100],size;
    cout<<"enter the size of array :\n";
    cin>>size;
    cout<<"Enter the elements of array :\n";
    for (int i = 0; i < size; i++)
    {
        cin>>a[i];
    }
    sort012(a,size);
   
    
    cout<<"The sorted array :\n";
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}
