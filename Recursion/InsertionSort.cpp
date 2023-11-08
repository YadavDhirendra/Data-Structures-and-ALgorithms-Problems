//Insertion sort by recursion
#include <bits/stdc++.h>
using namespace std;

void InsertionSort(int *arr, int size, int i)
{
    //base case
    if (i==size)
        return;

    int temp = arr[i];
    int j = i - 1;

    //ek kadam
    while (j >=0)
    {
        if (arr[j] > temp)
        {
            //shift
            arr[j + 1] = arr[j];
        }
        else
        { //ruk jao
        break;
        }
        j--;
    }
    arr[j+1]=temp;

    return InsertionSort(arr,size,i+1);
}

int main()
{
    int arr[] = {10, 1, 7, 4, 8, 2, 11};
    int size = 7;
    int i=1;
     InsertionSort(arr,size,i);
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}