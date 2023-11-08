//First and Last Position of an element in Sorted array
#include <bits/stdc++.h>
using namespace std;

int Occurences(int *arr, int s, int e, int key,int count)
{

    //base case
    if (s > e)
    {
   
        return 0;
    }

    int mid = s + (e - s) / 2;

    //element found
    if (arr[mid] == key)
    {
       
        for (int i = mid; i <= e; i++)
        {
            if (arr[i] == key)
            count++;
        }
        return count;
    }

    //left shift
    if (arr[mid] > key)
        Occurences(arr, s, mid - 1, key,count);

    //right shift
    if (arr[mid] < key)
        Occurences(arr, mid + 1, e, key,count);
}

int main()
{
    int arr[] = {0, 1, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0, e = n - 1, key = 1,count=0;;
   
    cout<<"The total no. of occurences of "<<key<<" is "<<Occurences(arr,s,e,key,count);

    return 0;
}