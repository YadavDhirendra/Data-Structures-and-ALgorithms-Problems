//Write a program to find the pivot element
#include <iostream>
using namespace std;

int pivot(int a[], int size)
{
    int s = 0, e = size - 1;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        if (a[mid] >= a[0])
            s = mid + 1;
        else
            e = mid;

    }
    return s;
}
int main()
{
    int a[100], size;
    cout << "Enter the size of array :\n";
    cin >> size;
    cout << "Enter the elements of array :\n";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    cout<<"Pivot index is "<<pivot(a,size);
    return 0;
}