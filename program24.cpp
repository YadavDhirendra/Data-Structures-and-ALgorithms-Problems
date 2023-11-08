//Problem : You are given an array 'ARR' of size 'N' and on integer 'S'. Your task is to return the list of all pairs of element such that each sum of elements of each pair equals 'S'.
#include<iostream>
using namespace std;
void read(int a[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cin>>a[i];
    }
    
}
void pairs(int a[], int size, int sum)
{
    for (int  i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (a[i]+a[j]==sum)
            {
                cout<<"("<<a[i]<<","<<a[j]<<")\t";
            }
            
        }
        
    }
    
}
int main()
{
    int arr[100],n,s;
    cout<<"Enter the size of array :\n";
    cin>>n;
    cout<<"Enter the elements of array :\n";
    read(arr,n);
    cout<<"Enter the integer for which u want the pairs :";
    cin>>s;
    pairs(arr,n,s);
    return 0;
}