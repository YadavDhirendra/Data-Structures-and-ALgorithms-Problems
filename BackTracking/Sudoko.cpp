//Solve Sudoko
//You have given a 9x9 2d Matrix 'MAT' representing a sudoko puzzle.The empty cels of the 
//sudoko are filled with with zeroes, and the rest of the cells are filled with integers 
//from 1 to 9. Your task is to fill all the empty cells such that the find matrix represents
//a sudoko solution.
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,int val,vector<vector<int>> &board,int n)
{
    for (int i = 0; i < n; i++)
    {
        //row check
        if(board[row][i] == val)
        return false;

        //column check
        if(board[i][col] == val)
        return false;

        //3*3 matrix check
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
        return false;

    }
    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board[0].size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //cell empty
            if(board[row][col] == 0)
            {
                for (int val = 1; val < 10; val++)
                {
                    if(isSafe(row,col,val,board,n))
                    {
                        board[row][col] = val;

                        bool aageSolutionPossible = solve(board);

                        if(aageSolutionPossible)
                        {
                            return true;
                        }
                        else
                        {
                            //If aage solution not possible by that val then backtrack
                            board[row][col] = 0;

                        }
                    }
                }
                return false;
            }
        }
        
    }
    return true;
}

void solvesudoko(vector<vector<int>> &sudoko)
{
    solve(sudoko);
}

int main()
{
    vector<vector<int>> sudoko = {  {3,0,6,5,7,8,0,9,2},
                                    {5,2,9,1,3,4,7,6,8},
                                    {4,8,0,6,2,9,5,3,1},
                                    {2,6,3,4,1,5,9,8,7},
                                    {9,7,4,8,6,3,1,2,5},
                                    {8,5,1,7,9,2,6,4,3},
                                    {1,3,8,9,4,7,2,5,6},
                                    {6,9,2,3,5,0,8,7,4},
                                    {7,4,5,2,8,6,3,1,9}};
    solvesudoko(sudoko);
    for(auto i:sudoko)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
