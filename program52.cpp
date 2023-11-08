//rotate the 2D array by 90 deg.
#include<bits/stdc++.h>
using namespace std;
void rotate(int a[][100],int m,int n)
{
    int ans[100][100], k=n-1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j]=a[j][k];
        }
        k--;
    }
    //re-initialising array
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j]=ans[i][j];
        }
        
    }
    
}
void print(int a[][100],int m,int n)
{
    cout<<"The elements of array are ::\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
int main()
{
    int a[100][100],m,n;
    cout<<"Enter the no. of rows ::\n";
    cin>>m;
    cout<<"Enter the no. columns ::\n";
    cin>>n;
    cout<<"Enter the elements of array ::\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
        
    }
    rotate(a,m,n);
    print(a,m,n);
    return 0;
}