//Cycle Detection in Directed Graph

#include <bits/stdc++.h>
using namespace std;

bool dfsCycle(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,unordered_map<int,list<int>> &adj)
{
    //mark all visited true
    visited[node] = 1;
    dfsvisited[node] = 1;

    for(auto neighbour : adj[node])
    {
        if(!visited[neighbour])
        {
            bool ans = dfsCycle(neighbour,visited,dfsvisited,adj);
            if(ans)
            return true;
        }
        else if(dfsvisited[neighbour])//both visited then return true
        return true;
    }

    //backtrak dfsvisited before call back
    dfsvisited[node] = 0;
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    //create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;
    //call dfs for all components
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool ans = dfsCycle(i, visited, dfsvisited, adj);
            if (ans)
                return true;
        }
    }

    return false;
}

int main()
{
    vector<pair<int,int>> edges = {{1,2},
                                    {2,3},
                                    {3,4},
                                    {4,5},
                                    {5,1}};
    if(detectCycleInDirectedGraph(5,edges))
    cout<<"Cycle present"<<endl;
    else
    cout<<"Sorry Cycle not present"<<endl;
    return 0;
}