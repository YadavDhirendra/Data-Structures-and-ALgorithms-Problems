//Problem : Given an integer array nums of length n, where all the integers of nums are in the range {1,n} and each integer appears once or twice ,returns an array of all the integers that appears twice.
#include<iostream>
using namespace std;
void duplicate(int a[],int size)
{
    for (int i = 0; i < size; i++)
    {   
        int temp=0;
        for (int j = i+1; j < size; j++)
        {
           if(a[i]==a[j]) 
           {
               temp=1;
               break;
           }
        }
       if(temp==1)
       cout<<a[i]<<" ";
    }
    
}
int main()
{
    int nums[100],size;
    cout<<"Enter the size of array :\n";
    cin>>size;
    for (int i = 0; i < size; i++)
    {
        cin>>nums[i];
    }
    cout<<"The duplicate numbers are :\n";
    duplicate(nums,size);
    return 0;
}