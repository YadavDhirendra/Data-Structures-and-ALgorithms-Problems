//First and Last Position of an element in Sorted array
#include <bits/stdc++.h>
using namespace std;

void firstandlast(int *arr, int s, int e, int key)
{

    //base case
    if (s > e)
    {
        cout << "-1 ";
        return;
    }

    int mid = s + (e - s) / 2;

    //element found
    if (arr[mid] == key)
    {
        cout << mid << " ";
        for (int i = mid + 1; i <= e; i++)
        {
            if (arr[i] == key)
            cout<<i<<" ";
        }
    }

    //left shift
    if (arr[mid] > key)
        firstandlast(arr, s, mid - 1, key);

    //right shift
    if (arr[mid] < key)
        firstandlast(arr, mid + 1, e, key);
}

int main()
{
    int arr[] = {0, 1, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int s = 0, e = n - 1, key = 1;
    cout << "The first and last position of " << key << " are ";
    firstandlast(arr,s,e,key);

    return 0;
}