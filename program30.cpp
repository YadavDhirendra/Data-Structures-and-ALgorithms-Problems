//Write a program to search a element in the reverse and sorted array.
#include<iostream>
using namespace std;

int pivot(int a[],int size)
{
    int s=0,e=size-1;
    while (s<e)
    {   
        int mid=s+(e-s)/2;

        if(a[mid]>=a[0])
        s=mid+1;

        else
        e=mid;

    }
    return s;
}
bool binarysearch(int a[],int size1,int size2,int key)
{
    int s=size1,e=size2-1;
    while (s<=e)
    {   
        int mid=s+(e-s)/2;
        if(a[mid]==key)
        {
            return 1;
        }

        else if(a[mid]>key)
        e=mid-1;

        else
        s=mid+1;
    }
    return 0;
    
}
int main()
{
    int a[100],size,key;
    cout<<"Enter the size of array :\n";
    cin>>size;
    cout<<"ENter the elements of array :\n";
    for (int i = 0; i < size; i++)
    {
        cin>>a[i];
    }
    cout<<"ENter the no. u want to search :\n";
    cin>>key;
    int p=pivot(a,size),temp=0;
    if(a[p]<=key && a[size-1]>=key)
    {
        temp=binarysearch(a,p,size,key);
    }
    else
    {
        temp=binarysearch(a,0,p-1,key);
    }
    if(temp==1)
    cout<<"keY is Found!";
    else
    cout<<"sorry! Key is not Found.";
    return 0;
}