#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n,int m,vector<vector<int>> &edges)
{
    vector<int> ans[n];
    //answer array will store all neighbours
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[i].push_back(i);
        //entering all neighbours
        for (int j = 0; j < ans[i].size(); j++)
        {   
            adj[i].push_back(ans[i][j]);
        }
        
    }
    return adj;
}

int main()
{
    vector<vector<int>> edges = {{4,3},
                                {1,2},
                                {0,3},
                                {2,3},
                                {3,3},
                                {0,1},
                                {2,0}};
    vector<vector<int>> adj = printAdjacency(5,7,edges);
    for(auto i:adj)
    {
        for(auto j :i)
        cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}