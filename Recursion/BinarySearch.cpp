//Binary search by recursion
#include<bits/stdc++.h>
using namespace std;

bool BinarySearch(int *arr,int s,int e,int key)
{
    //base case
    if(s>e)
    return false;

    int mid = s + (e-s)/2;
    

    if(arr[mid]==key)
    return 1;
    if(arr[mid]>key)
    return BinarySearch(arr,s,mid-1,key);
    if(arr[mid]<key)
    return BinarySearch(arr,mid+1,e,key);

}

int main()
{
     int arr[6]={2,5,7,8,9,10};
    int size =6;
    int key=5;
    int s=0,e=size-1;

    if(BinarySearch(arr,s,e,key))
    cout<<"Key is found";
    else
    cout<<"Sorry key is not found!";
    return 0;
}