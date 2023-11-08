//Peak in a mountain
//Note : given an integer arrau arr that is guarranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i-1] < arr[i] > arr[i+1] > .... > arr[arr.length-1]
#include<bits/stdc++.h>
using namespace std;


int peakinAmountain(int *arr,int s,int e){

    //base case
    if(s>e)
    return -1;

    int mid = s + (e-s)/2;

    if(s<e){
    //left side of mountain representing non-dec order elements
    if(arr[mid]<arr[mid+1])
    return peakinAmountain(arr,mid+1,e);
    
    //right side or peak of mountain representing non-inc order elements
    else
    return peakinAmountain(arr,s,mid);

    return s;
    }

}
int main()
{
    int arr[]={0,1,5,2,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    int s=0,e=size-1;
   
    cout<<"The peak in given array is "<<peakinAmountain(arr,s,e);
    return 0;
}