//binary search in 2D array
#include<bits/stdc++.h>
using namespace std;
bool binary(int a[][100],int m,int n,int key)
{
    int s=0,e=m*n-1;
    int row=m,col=n;
    while (s<=e)
    {
        int mid=s+(e-s)/2;

        if(a[mid/col][mid%col]==key)
        return 1;

        else if(a[mid/col][mid%col]>key)
        e=mid-1;

        else
        s=mid+1;

    }
    
    return 0;
}
int main()
{
    int a[100][100]={{1,2,3},{4,5,6},{7,8,9}};
    int key;
    cout<<"Enter the element u want 2 search ::\n";
    cin>>key;
    if(binary(a,3,3,key))
    cout<<"Congrats! Key is found.";
    else
    cout<<"Sorry Key is not found.";
    
    return 0;
}