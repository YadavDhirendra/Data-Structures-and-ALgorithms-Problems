//Linear search by recursion
#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int*arr,int size,int key)
{
    //base case
    if(size==0)
    return 0;
    
    if(arr[0]==key)
    return 1;

    int remainingPart = linearSearch(arr+1,size-1,key);
    return remainingPart;
}

int main()
{
    int arr[6]={2,7,8,10,6,5};
    int size =6;
    int key=10;

    if(linearSearch(arr,size,key))
    cout<<"Key is found";
    else
    cout<<"Sorry key is not found!";
    
    return 0;
}