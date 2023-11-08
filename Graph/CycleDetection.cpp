//cycle detection in Undirected Graph
#include<bits/stdc++.h>
using namespace std;

bool isCyclicBFS(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> adj)
{
    unordered_map<int,int> parent;

    parent[node] = -1;
    visited[node] = 1;
    queue<int> q;
    q.push(node);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for(auto neighbour : adj[frontNode])
        {
            if(visited[neighbour]  && neighbour!=parent[frontNode])
            return true;
            else if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

bool isCyclicDFS(int node,int parent,unordered_map<int,bool> &visited,unordered_map<int,list<int>> adj)
{
    visited[node] = 1;

    for(auto neighbour:adj[node])
    {
        if(!visited[neighbour])
        {
            bool ans = isCyclicDFS(neighbour,node,visited,adj);
            if(ans)
            return true;
        }
        else if(neighbour != parent)
        {
            //cycle present
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges,int n,int m)
{
    //create adjacency list
    unordered_map<int,list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    

    unordered_map<int,bool> visited;
    //to handle disconnected components
    for (int  i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            bool ans = isCyclicDFS(i,-1,visited,adj);
            if(ans)
            return "Yes";

        }
    }
    return "NO";
}

int main()
{
     vector<vector<int>> edges = { {1,2},
                                    {2,3},
                                    {4,5},
                                    {5,6},
                                    {6,8},
                                    {7,8},
                                    {5,7},
                                    {8,9}};
    int n = 9, m = 8;
    cout<<"cycle is present or not : "<<cycleDetection(edges,n,m)<<endl;
    return 0;
}