//spiral print of an array
/* 1 2 3        
   4 5 6   ->  1 2 3 6 9 8 7 4 5
   7 8 9    */
#include <bits/stdc++.h>
using namespace std;
void spiral(int a[][100], int m, int n)
{
    
    int startingrow = 0;
    int endingrow = m-1 ;
    int startingcol = 0;
    int endingcol = n-1 ;
    int count = 0, total = m * n;
    // int ans[100][100];
    while (count<total)
    {
        
    //for starting row
    for (int i = startingcol; i <= endingcol && count<total; i++)
    {
        cout<<a[startingrow][i]<<" ";
        count++;
    }
    startingrow++;
    
    //for ending column
    for (int i = startingrow; i <=endingrow && count<total  ; i++)
    {
        cout<<a[i][endingcol]<<" ";
        count++;
    }
    endingcol--;

    //for ending row
    for (int i = endingcol; i >=startingcol && count<total; i--)
    {
       cout<<a[endingrow][i]<<" ";
       count++; 
    }
    endingrow--;

    //for starting column
    for (int i = endingrow; i >=startingrow && count<total; i--)
    {
        cout<<a[i][startingcol]<<" ";
        count++;
    }
    startingcol++;
    }
    
}
int main()
{
    int a[100][100], m, n;
    cout << "Enter the no. of rows ::\n";
    cin >> m;
    cout << "Enter the no. columns ::\n";
    cin >> n;
    cout << "Enter the elements of 2D array ::\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    spiral(a,m,n);
    return 0;
}