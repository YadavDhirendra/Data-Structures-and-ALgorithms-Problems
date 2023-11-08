//Problem : You are given an array of size 'N' containing each element between 1 and N-1 atleast once. There is a number that present in the array twice. Your task is to find the duplicate integer value present in the array.
//Logic : 0^a = a and a^a=0.
#include<iostream>
using namespace std;

int main()
{
    int a[100],size,ans=0;
    cout<<"ENter the size of array :\n";
    cin>>size;
    cout<<"Enter the elements of array :\n";
    for (int i = 0; i < size; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < size; i++)
    {
        ans=ans^a[i];
    }
    for (int i = 1; i < size; i++)
    {
        ans=ans^i;
    }
    cout<<"The duplicate element is "<<ans;
    return 0;
}