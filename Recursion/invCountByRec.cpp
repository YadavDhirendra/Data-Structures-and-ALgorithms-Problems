//inversion count problem by merge sort
#include <bits/stdc++.h>
using namespace std;

int merge(int *arr, int *temp, int s,int mid, int e)
{
    
    int inv_count = 0;

    int i = s, j = mid, k = s;
    while ((i < mid - 1) && (j <= e))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + mid - i;
        }
    }

    ////bache hue elements
    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= e)
    {
        temp[k++] = arr[j++];
    }
    //copy back the merged elements to original array
    for (int i = s; i <= e; i++)
    {
        arr[i] = temp[i];
    }
    return inv_count;
}

int mergeSort(int *arr, int *temp, int s, int e)
{
    int mid = s + (e - s) / 2;
    int inv_count = 0;
    //base case
    if(s>e){
    inv_count += mergeSort(arr, temp, s, mid);
    inv_count += mergeSort(arr, temp, mid + 1, e);

    inv_count += merge(arr, temp, s,mid+1, e);
    }
    return inv_count;
}
int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int s=0,e=size-1;
    int temp[size];
    cout<<"The iversion count of given array is : "<<mergeSort(arr,temp,s,e);
    return 0;
}