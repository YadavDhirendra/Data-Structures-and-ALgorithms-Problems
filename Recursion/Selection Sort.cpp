//Selection sort by using recusrion
#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int *arr,int size)
{
    //base case
    if(size==0||size==1)
    return ;

    int j=0;
    //ek kadam
    for (int i = 1; i < size; i++)
    {
        if(arr[j]>arr[i])
        {
            swap(arr[j],arr[i]);
        }
    }

    //baki ye sambhal lega
   return SelectionSort(arr+1,size-1);
}

int main()
{
    int arr[6]={6,2,11,7,8,1};
    int size =6;
    SelectionSort(arr,size);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
