//quick sort
#include<bits/stdc++.h>
using namespace std;

int partition(int *arr,int s,int e)
{
    int count=0;
    int pivot = arr[s];
   
    for (int i = s+1; i <= e; i++)
    {
        if(arr[i]<=pivot)
        count++;
    }
    //place pivot at right position
    int pivotIndex = s+count;
    swap(arr[pivotIndex],arr[s]);

    //left and right wala part sambhal lena
    int i=s,j=e;

    while (i<pivotIndex && j> pivotIndex)
    {
        if(arr[i]<pivot)
        i++;
        if(arr[j]>pivot)
        j--;
        if(arr[i]>pivot && arr[j]<pivot)
        swap(arr[i++],arr[j--]);
    }
    return pivotIndex;
}

void quickSort(int *arr,int s,int e)
{
    //base case
    if(s>=e)
    return ;

    int p =partition(arr,s,e);

    quickSort(arr,s,p-1);

    quickSort(arr,p+1,e);

}

int main()
{
    int arr[]={2,4,44,11,0,1,4,1,11};
    int size = sizeof(arr)/sizeof(arr[0]);
    int s=0,e=size-1;
    quickSort(arr,s,e);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}