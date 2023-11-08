/*Bubble Sort*/
#include <bits/stdc++.h>
using namespace std;
void bubblesort(int a[], int n)
{
    int k ;
    for (int i = 0; i < n-1; i++)
    {   
        int k=0;
        for (int j = 1; j < n-i; j++)
        {
           if(a[k]>a[j]) 
           swap(a[k],a[j]);
           k++;
        }
        
    }  
}
void printarray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i]<<" ";
    }
}
int main()
{
    int a[100], size;
    cout << "Enter the size of array :\n";
    cin >> size;
    cout << "Enter the elements of array ::\n";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    bubblesort(a, size);
    cout << "The sorted elements of array :\n";
    printarray(a, size);

    return 0;
}