//BFS in Graph
//You are given an undirected graph and disconnected graph G(V,E) having V vertices numbered
// from 0  to V-1. Your task is to print its BFS traversal starting from the 0th vertices.
#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<int> > adj, vector<pair<int, int> > edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int> > adj, unordered_map<int, bool> visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        //store frontNode into ans
        ans.push_back(frontNode);

        //traverse all neighbours of frontNode
        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int> > &edges)
{
    unordered_map<int,list<int> > adj;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepareAdjList(adj, edges);

    //traverse all component of a graph
    for (int i = 1; i <= vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adj, visited, ans, i);
        }
    }
    return ans;
}

int main()
{
    vector<pair<int,int> > edges = {{1,2},
                                    {2,3},
                                    {4,5},
                                    {5,6},
                                    {6,8},
                                    {7,8},
                                    {5,7},
                                    {8,9}};
    int vertex = 9;
    vector<int> ans = BFS(vertex,edges);
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}