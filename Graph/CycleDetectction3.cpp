//Cycle detection in Directed Graph by BFS(Kahn's rev algo)
#include<bits/stdc++.h>
using namespace std;

string cycleDetection(vector<vector<int>> &edges,int v,int e)
{
    //create adj list
    unordered_map<int,list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }
    
    //create indegree array
    vector<int> indegree(v+1);
    for(auto i:adj)
    {
        for(auto j:i.second)
        indegree[j]++;
    }
    
    int cnt = 0;

    //0 idegree wale insert karo
    queue<int> q;
    for (int i = 1; i <= v; i++)
    {
        if(indegree[i] == 0)
        q.push(i);
    }
    
    //do bfs
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        //inc cnt
        cnt++;

        for(auto neighbour:adj[front])
        {
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
            q.push(neighbour);
        }
    }
    
    //if valid topological sort return false else true
    if(cnt == v)
    return "No";
    else
    return "Yes";
}

int main()
{
   vector<vector<int>> edges = {{1,2},
                                {4,1},
                                {2,4},
                                {3,4},
                                {5,2},
                                {1,3}};
    int n = 5,m = 6;
    cout<<"cycle is present or not : "<<cycleDetection(edges,n,m)<<endl;
    return 0;
}