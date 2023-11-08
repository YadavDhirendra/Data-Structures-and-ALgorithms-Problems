//Problem : You have been given an integer arraylist 'ARR' of size 'N'. It contains only 0s,1s and 2s.Write a solution to sort this arraylist.
//Condition : Try to solve this problem in 'single scan' ,'Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be visiting each element in the array/list just case.
#include<iostream>
using namespace std;

int sort012(int a[],int size)
{
    int count0=0,count1=0,count2=0,i=0;//variables to count 0,1 and 2
    while (i<size)
    {
        switch (a[i])
        {
        case 0:
            count0++;
            break;
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        }
        i++;
    }
   
   //Update the array
   i=0;
   //Store all the 0s in the beginning
   while (count0>0)
   {
       a[i++]=0;
       count0--;
   }
   
   //Then all the 1s
   while (count1>0)
   {
       a[i++]=1;
       count1--;
   }
   
   //Finally all the 2s
   while (count2>0)
   {
       a[i++]=2;
       count2--;
   }
   
    
}
void printarray(int a[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    
}
//Driver code
int main()
{
    int arr[100],size;
    cout<<"Enter the size of array :\n";
    cin>>size;
    cout<<"Enter the elements of array ::\n";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    sort012(arr,size);
    printarray(arr,size);
    return 0;
}