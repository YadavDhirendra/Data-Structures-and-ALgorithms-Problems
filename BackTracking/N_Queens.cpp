//The N Queens puzzle is the problem of placing N chess queens on an N*N chessboard such 
//that no two queens attack on each other .
//Given an integer 'N' ,print all distinct solutions to the 'N' queen puzzle.
//Two queens on the same chessboard can attack each other if any of the below condition 
//satisfies :
//1.They share a row.
//2.They share a column.
//3.They share a diagonal.
#include<bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<int>> &board,vector<vector<int>> &ans,int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
        
    }
    ans.push_back(temp);
}
bool isSafe(int row,int col,vector<vector<int>> &board,int n)
{
    //As we r heading from left to right so we don't have to check right side paths
    //And also we r inserting queen col to col so we already ensured that only one 
    //queen in one column

    int x = row;
    int y = col;
    //left row
    while (y>=0)
    {
        if(board[x][y] == 1)
        return false;
        y--;
    }
    
    //left upper diagonal
    x = row;
    y = col;
    while (x>=0 && y>=0)
    {
        if(board[x][y] == 1)
        return false;
        x--;
        y--;
    }
    
    //left lower diagonal
    x = row;
    y = col;
    while (x<n && y>=0)
    {
        if(board[x][y] == 1)
        return false;
        x++;
        y--;
    }
    
    return true;
}
void solve(int col,vector<vector<int>> &ans,vector<vector<int>> &board, int n)
{
    //base case
    if(col == n)
    {
        addSolution(board,ans,n);
        return;
    }

    //solve 1 case and rest RECURSION will take care

    for (int  row = 0; row < n; row++)
    {
        if(isSafe(row,col,board,n))
        {
            //if placing queen is safe
            board[row][col] = 1;
            solve(col+1,ans,board,n);
            //backtrack
            board[row][col] = 0;
        }
    }
    
}

vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> board (n,vector<int>(n,0));
    vector<vector<int>> ans;
    
    solve(0,ans,board,n);
    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> ans = nQueens(n);
    for(auto i:ans)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }
    
    return 0;
}