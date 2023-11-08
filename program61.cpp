//Write a program to cyclically rotate an array by one
#include<bits/stdc++.h>
using namespace std;
void rotate(int a[],int n)
{
    int i=0,j=0,ans[100];
    while (i<n)
    {
        ans[i]=a[(i-1)%n];
        i++;
    }
    
    for (int i = 0; i < n; i++)
    {
        a[i]=ans[i];
    }
    
}
void print(int a[],int n)
{
    cout<<"The rotated array is ::\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}
int main()
{
    int a[100],n;
    cout<<"Enter the size of array ::\n";
    cin>>n;
    cout<<"Enter the elements of array ::\n";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    rotate(a,n);
    print(a,n);
    return 0;
}