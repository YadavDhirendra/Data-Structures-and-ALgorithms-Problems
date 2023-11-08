/* Write an efficient algorithm that seaches for a target value in an m x n integer matrix. The matrix has the following properties.
     -> Integers in each rows are stored in ascending from left to right.
     -> Integers in each column are stored in ascending from top to bottom.
     e.g., 1    4   7   11  15
           2    5   8   12  19
           3    6   9   16  20
          10    13  14  17  24
          18    21  23  26  30      */
#include <bits/stdc++.h>
using namespace std;
bool binary(int a[][100],int row,int col,int key)
{
    int s=0;//starting row;
    int e=col-1;//ending column
    // int total=m*n;
    while (e>=0 && s<row)
    {
        if (a[s][e]==key)
        return 1;

        else if(a[s][e]>key)
        e--;

        else
        s++;
        
    }
   return 0; 

}
int main()
{
    int a[100][100] = {{1, 4, 7, 11, 15},
                       {2, 5, 8, 12, 19},
                       {3, 6, 9, 16, 20},
                       {10, 13, 14, 17, 24},
                       {18, 21, 23, 26, 30}};
    int key;
    cout<<"Enter the element u want 2 search ::\n";
    cin>>key;
    if(binary(a,5,5,key))
    cout<<"Congrats! Key is found.";
    else
    cout<<"Sorry Key is not found.";
    return 0;
}