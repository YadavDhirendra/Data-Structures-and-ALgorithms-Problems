//Rat in a maze problem
#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> m,vector<vector<int>> visited,int newx,int newy,int n)
{
    if((newx>=0 && newx<n) && (newy>=0 && newy<n) && (visited[newx][newy]==0) && (m[newx][newy]==1))
    return true;
    else
    return false;
}

void RatInAMaze(vector<vector<int>> m, vector<vector<int>> visited, vector<string> &ans, string path, int n, int x, int y)
{
    //Now we are at x and y

    //base case
    if ((x==n-1 && y==n-1) || n==0 || m[0][0]==0)
    {
        ans.push_back(path);
        return;
    }

    //being on x and y updating visited matrix
    visited[x][y] = 1;

    //for 'Down' movement
    int newx = x + 1;
    int newy = y;
    if (isSafe(m, visited, newx, newy,n))
    {
        path.push_back('D');
        RatInAMaze(m, visited, ans, path, n, newx, newy);
        //backtracking for new path
        path.pop_back();
    }

    //for 'Up' movement
     newx = x - 1;
     newy = y;
    if (isSafe(m, visited, newx, newy,n))
    {
        path.push_back('U');
        RatInAMaze(m, visited, ans, path, n, newx, newy);
        //backtracking for new path
        path.pop_back();
    }

    //for 'Right' movement
     newx = x;
     newy = y + 1;
    if (isSafe(m, visited, newx, newy,n))
    {
        path.push_back('R');
        RatInAMaze(m, visited, ans, path, n, newx, newy);
        //backtracking for new path
        path.pop_back();
    }

    //for 'Left' movement
     newx = x;
     newy = y - 1;
    if (isSafe(m, visited, newx, newy,n))
    {
        path.push_back('L');
        RatInAMaze(m, visited, ans, path, n, newx, newy);
        //backtracking for new path
        path.pop_back();
    }

    //backtracking for new path
    visited[x][y] = 0;
}

int main()
{
    vector<vector<int>> m = {{1, 0, 0, 1},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};
    int n = 4;
    
    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    vector<string> ans;
    string path="";

    RatInAMaze(m,visited,ans,path,n,0,0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    
    return 0;
}