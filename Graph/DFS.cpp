//DFS in Graph
#include<bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int,list<int>> &adj,vector<vector<int>> &edges,int E)
{
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    
}

void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj,vector<int> &component)
{
    component.push_back(node);
    visited[node] = 1;

    //har connected node k liye recursive calls
    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            dfs(i,visited,adj,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V,int E,vector<vector<int>> &edges)
{
    //prepare adjList
    unordered_map<int,list<int>> adj;
    prepareAdjList(adj,edges,E);

    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    for (int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            vector<int> component;
            dfs(i,visited,adj,component);
            ans.push_back(component);//component wise traversal
        }
    }
    return ans;
}

int main()
{
    int v = 5,e = 4;
    vector<vector<int>> edges = {{0,2},
                                 {0,1},
                                 {1,2},
                                 {3,4}};
    vector<vector<int>> ans = depthFirstSearch(v,e,edges);
    for(auto i:ans)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}