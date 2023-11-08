//Write a program to find the unique element in an array.
#include <iostream>
using namespace std;
int unique(int a[], int size)
{
    int  i, j;
    for (i = 0; i < size; i++)
    {   
        int temp=0;
        for (j = 0; j < size; j++)
        {
            if (i != j)
            {
                if (a[i] == a[j])
                {
                    temp = 1;
                }
            }
        }
        if (temp == 0)
            break;
    }
    return a[i];
}
int main()
{
    int a[100], n, test;
    cout << "Enter the no. of test :\n";
    cin >> test;
    while (test != 0)
    {
        cout << "Enter the size of array :\n";
        cin >> n;
        cout<<"Enter the elements of array :\n";
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int x = unique(a, n);
        cout << "The unique element of above array is = " << x << endl;
        test--;
    }

    return 0;
}