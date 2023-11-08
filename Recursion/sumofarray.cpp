//Use recursion to give sum of an array
#include<bits/stdc++.h>
using namespace std;

int summation(int *arr,int size)
{
    //base case
    if(size==1)
    return arr[0];

    //recursive call
    return arr[0]+summation(arr+1,size-1);
}

int main()
{
    int arr[5]={2,5,6,8,9};
    int size=5;
    int sum = summation(arr,size);
    cout<<"The sum of array is : "<<sum;
    return 0;
}