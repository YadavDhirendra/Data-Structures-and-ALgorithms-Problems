//Problem : You have been given a sorted array ARR containing of 'N' elements. You are also given an integer 'K'.
// NOte : Your task is to find the total no. of occurences of 'K' in ARR.
#include<iostream>
using namespace std;

int firstocc(int a[],int size ,int key)
{

    int s=0,e=size-1,temp;
    while (s<=e)
    {
        int mid=s+(e-s)/2;
        if (a[mid]==key)
        {   
            temp=mid;
            e=mid-1;
        }
        
        //Right approach
        else if(a[mid]<key)
        s=mid+1;

        //Left approach
        else if(a[mid]>key)
        e=mid-1;

    }
    return temp;
    
}
int secondocc(int a[],int size ,int key)
{

    int s=0,e=size-1,temp;
    while (s<=e)
    {
        int mid=s+(e-s)/2;
        if (a[mid]==key)
        {   
            temp=mid;
            s=mid+1;
        }
        
        //Right approach
        else if(a[mid]<key)
        s=mid+1;

        //Left approach
        else if(a[mid]>key)
        e=mid-1;

    }
    return temp;
    
}
int main()
{
    int size,arr[100],key;
    cout<<"Enter the size of array :\n";
    cin>>size;
    cout<<"Enter the elements of array :\n";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    
    }
    cout<<"ENter the key to search in array:\n";
    cin>>key;

    int first = firstocc(arr,size,key);
    int second = secondocc(arr,size,key);
    int z= second-first +1;

    cout<<"The total no. of occurrences is "<<z;
    return 0;
}