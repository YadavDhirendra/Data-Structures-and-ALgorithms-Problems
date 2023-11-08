//Wave print of 2D array 
#include<bits/stdc++.h>
using namespace std;
void waveprint(int a[][100],int m,int n)
{   
    cout<<"THe wave pattern of given array is ::\n";  
    for (int i = 0; i < n; i++)
    {
        if(i&1)//odd no. of column
        {
            for (int j = m-1; j >=0; j--)
                cout<<a[j][i]<<" ";
            
        }
        else//even no. of column
        {
            for (int j = 0; j <m; j++)
                cout<<a[j][i]<<" ";

        }
        cout<<endl;
    }
    
    
}
int main()
{
    int a[100][100],m,n;
    cout<<"Enter the row of array ::\n";
    cin>>m;
    cout<<"Enter the column of array ::\n";
    cin>>n;
    cout<<"Enter the elements of array ::\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>a[i][j];
        }
        
    }
    waveprint(a,m,n);
    return 0;
}
