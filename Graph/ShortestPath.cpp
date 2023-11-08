//Shortest Path in an unweighted graph
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges, int n,int m,int s,int t)
{
    //create adjacency list
    unordered_map<int,list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //do bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;

    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for(auto neighbour:adj[front])
        {
            if(!visited[neighbour])
            {
                visited[neighbour] = 1;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }
    
    vector<int> ans;
    int currentNode = t;
    ans.push_back(currentNode);
    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    vector<pair<int,int>> edges = { {1,2},
                                    {2,5},
                                    {5,8},
                                    {1,3},
                                    {3,8},
                                    {1,4},
                                    {4,6},
                                    {6,7},
                                    {7,8}};
    int n = 8, m = 9;
    int s = 1, t = 8;
    vector<int> shortpath = shortestPath(edges,n,m,s,t);
    for(auto i:shortpath)
    cout<<i<<" ";
    cout<<endl;
    return 0;
}