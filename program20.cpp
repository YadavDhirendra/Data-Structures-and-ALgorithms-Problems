//Write a program that returns true if the number of occurences of each value in the array is unique , or false otherwise.
#include <iostream>
#include<algorithm>
using namespace std;
void read(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
}
bool unique(int a[], int size)
{
    int b[10], n = 0;
    for (int i = 0; i < size; i++)
    {
        b[n] = 0;
        for (int j = 0; j < size; j++)
        {
            int temp = 0;
            for (int k = 0; k < i; k++)
            {

                if (a[i] == a[k])
                    temp = 1;
            }
            if (temp == 1)
                continue;

            if (a[i] == a[j])
            {
                b[n]++;
            }

            n++;
        }
    }
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            if (b[i] == b[j])
            {
                temp = 1;
                break;
            }
        }
    }

    return temp;
}
int main()
{
    int arr[100], size, no;
    cout << "Enter the size of array :\n";
    cin >> size;
    read(arr, size);
    int n=size-1;
    sort(arr,arr+n);
    int x = unique(arr, size);
    if (x == 0)
        cout << "True";
    else
        cout << "False";
    return 0;
}
