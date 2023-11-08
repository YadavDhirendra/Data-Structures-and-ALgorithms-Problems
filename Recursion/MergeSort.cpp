//Merge sort
#include<bits/stdc++.h>
using namespace std;

void merge(int *arr,int s ,int e)
{
    int mid = s + (e-s)/2;
    int len1 = mid-s+1; //length for 1st array
    int len2 = e-mid; //length for 2nd array

    int *first = new int[len1];
    int *second = new int[len2];

    int mainIndex1 = s;
    for (int i = 0; i < len1; i++)
    {
        first[i]=arr[mainIndex1++];
    }
    
    int mainIndex2 = mid+1;
    for (int i = 0; i < len2; i++)
    {
        second[i]=arr[mainIndex2++];
    }

    //ab merge krna h
    int i=0,j=0;
    while (i<len1 && j<len2)
    {
        if(first[i]>second[j])
        arr[s++]=second[j++];
        else
        arr[s++]=first[i++];
    }
    
    //bache khuche elements ke liye
    while (i<len1)
    {
        arr[s++]=first[i++];
    }

    while (j<len2)
    {
        arr[s++]=second[j++];
    }
    
    //inka ab kaam khatam
    delete []first;
    delete []second;

}

void mergeSort(int arr[],int s,int e)
{
    //base case
    if(s>=e)
    return ;

    int mid = s + (e-s)/2;

    //left part sort kr do recursion bhaiya
    mergeSort(arr,s,mid);

    //right part sort kr do recursion bhaiya
    mergeSort(arr,mid+1,e);

    //merge kr do bro
    merge(arr,s,e);  //just like merging two sorted arrays one array is from s to mid and second one is from mid+1 to e...
}

int main()
{
    int arr[]={4,11,2,12,12,1,0,0,77};
    int size=9;
    int s=0,e=size-1;
    mergeSort(arr,s,e);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}