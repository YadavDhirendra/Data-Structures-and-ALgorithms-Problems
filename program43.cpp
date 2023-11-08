//move zeroes
#include <bits/stdc++.h>
using namespace std;
void movezero(int a[], int n)
{
    //counting of zeroes
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            m++;
    }
    //inserting non-zero elements
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            a[j++] = a[i];
        }
    }
    //inserting zeroes
    for (int i = j; i < n; i++)
    {
        a[i] = 0;
    }
}
void print(int a[],int n)
{   
    cout<<"The elements of array ::\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}
int main()
{
    int a[100], n;
    cout << "Enter the size of array ::" << endl;
    cin >> n;
    cout<<"Enter the elements of array ::\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    movezero(a,n);
    print(a,n);
    return 0;
}