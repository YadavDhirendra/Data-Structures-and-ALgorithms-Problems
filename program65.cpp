//initialixation of 2D array in dynamic memory
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cout<<"enter the no. of rows ::\n";
    cin>>m;
    cout<<"Enter the no. of columns ::\n";
    cin>>n;
    int **a= new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i]=new int[n];
    }
    cout<<"Enter the elements of array ::\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
        
    }
    cout<<"The given array is ::\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    for (int i = 0; i < m; i++)
    {
        delete [] a[i];
    }
    delete [] a;
    return 0;
}