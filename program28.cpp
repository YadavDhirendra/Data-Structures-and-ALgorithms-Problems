/*Let's call an array arr a 'Mountain array' if the following properties hold :
-> arr,length >=3
-> There exists some i with 0 < 1 < arr,length - 1 such that
        # arr[0] < arr[1] < .... arr[i-1] < arr[i]
        # arr[i] > arr[i+1] > .....>arr[arr.length-1]
Given an integer array arr that is guaranteed to be a mountain, return any 1 such that arr[0] < arr[1] < ..... arr[i-1] < arr[i] > arr[i+1] > .....> arr[arr.length-1]. */
#include<iostream>
using namespace std;

int peak(int a[],int size)
{
    int s=0,e=size-1,temp;
    while (s<e)
    {   
        int mid=s +(e-s)/2;
        if (a[mid]<a[mid+1])
        {
            s=mid+1;

        }
        else
        {
        e=mid;
        temp=e;
        }  
        
    }

    return temp;
}
int main()
{
    int arr[100],size;
    cout<<"Enter the size of array :\n";
    cin>>size;
    cout<<"Enter the elements of array :\n";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    
    int peek = peak(arr,size);
    cout<<"The peak index of above mountain array is "<<peek;
    return 0;
}
