//Bubble sort by recursion
//Bubble sort : for ith element n-i iteratoins run to sort ith element at the end
//key point :Ek kadam badhao baaki recursion sambhal lega
#include<bits/stdc++.h>
using namespace std;

void BubbleSort(int *arr,int size)
{
    //base case
    if(size==0||size==1)
    return ;

    //ek kadam
    for (int i = 0; i < size-1; i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }

    //baki ye sambhal lega
   return BubbleSort(arr,size-1);
}

int main()
{
    int arr[6]={6,2,4,7,8,1};
    int size =6;
    BubbleSort(arr,size);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
