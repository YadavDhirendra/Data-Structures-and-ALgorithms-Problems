//Problem : You are given two arrays 'A' and 'B' of size 'N' and 'M' respectively.Both these arrays are sorted in non-decreasing order.You have to find the intersection of these two arrays.
#include<iostream>
using namespace std;

//fuction for intersection of arrays
void intersection(int a[],int m,int b[], int n)
{   
    int c[100],k=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(a[i]==b[j])
            cout<<a[i]<<" ";
        }    
    }
    // for (int i = 0; i < k; i++)
    // {
    //     cout<<c[i]<<" ";
    // }
    
}
void read(int a[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cin>>a[i];
    }
    
}
int main()
{
    int a[100],m,b[100],n;
    cout<<"Enter the size of 1st array :\n";
    cin>>m;
    cout<<"Enter the elements of 1st array :\n";
    read(a,m);
    cout<<"Enter the size of 2nd array :\n";
    cin>>n;
    cout<<"Enter the elements of 2nd array :\n";
    read(b,n);
    intersection(a,m,b,n);

    return 0;
}