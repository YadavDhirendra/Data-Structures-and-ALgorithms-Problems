/*inversion count problem
Examples : i/p : arr[]={8,4,2,1}
o/p : 6
Explanation : Given array has six inversions : (8,4),(4,2),(8,2),(8,1),(4,1),(2,1)*/
#include<bits/stdc++.h>
using namespace std;

int inversionCount(int *arr,int size)
{
    int inv_count =0;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if(arr[i]>arr[j])
            inv_count++;
        }
        
    }
    return inv_count;
}

int main()
{
    int arr[]={8,4,2,1};
    int size=4;
    cout<<"The inverse count of given array is : "<<inversionCount(arr,size);
    return 0;
}
