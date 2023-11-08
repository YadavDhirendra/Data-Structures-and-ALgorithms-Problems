//is sorted array by recursion
#include<bits/stdc++.h>
using namespace std;

bool isSorted(int *arr,int size)
{
    //base case
    if(size==0||size==1)
    return true;

    if(arr[0]>arr[1])
    return false;

    //recusive call
    return isSorted(arr+1,size-1);
}

int main()
{
    int arr[5]={2,4,10,8,9};
    int size =5;
    
    bool ans=isSorted(arr,size);
    if(ans)
    cout<<"The array is sorted ";
    else
    cout<<"The array is not sorted..";
    return 0;
}