//Reverse an array
#include<bits/stdc++.h>
using namespace std;
void reverse(int a[],int n)
{
int s=0,e=n-1;
while (s<=e)
{
    swap(a[s],a[e]);
    s++,e--;
}
}
void print(int a[],int n)
{
    cout<<"The elements of array are ::\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}
int main()
{
    int a[100],n;
    cout<<"Enter the size of array :\n";
    cin>>n;
    cout<<"Enter the elements of array ::\n";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    reverse(a,n);
    print(a,n);
    return 0;
}