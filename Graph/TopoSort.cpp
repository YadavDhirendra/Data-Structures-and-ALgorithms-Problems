//Topological Sort
//Topological Sorting of DAG(Directed Acyclic(no cycles) Graph) is a linear ordering 
//of vertices such that for every directed edge from vertex from 'u' to vertex 'v'.
//Vertex 'u' comes before 'v' in the ordering.Topological Sorting for a graph
//is not possible if the graph is not a DAG.
#include<bits/stdc++.h>
using namespace std;

void dfsTopoSort(int node,stack<int> &s,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj)
{
    visited[node] = true;

    for(auto neighbour:adj[node])
    {
        if(!visited[neighbour])
        {
            dfsTopoSort(neighbour,s,visited,adj);
        }

    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges,int v,int e)
{
    //create adj list
    unordered_map<int,list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    
    stack<int> s;
    unordered_map<int,bool> visited;
    //call dfs topological sort util function for all component
    for (int i = 1; i <= v; i++)
    {
        if(!visited[i])
        {
            dfsTopoSort(i,s,visited,adj);
        }
    
    }
    
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main()
{
    vector<vector<int>> edges = {{1,2},
                                 {1,3},
                                 {3,4},
                                 {2,4},
                                 {4,5},
                                 {5,6},
                                 {4,6}};
    int v = 6,e = 7;
    vector<int> ans = topologicalSort(edges,v,e);
    for(auto i:ans)
    cout<<i<<" ";
    cout<<endl;
    return 0;
}