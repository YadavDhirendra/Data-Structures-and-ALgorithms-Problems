//Kahn's Algo(BFS) for Topological Sort
#include<bits/stdc++.h>
using namespace std;

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
    
    //create indegrees array
    vector<int> indegree(v+1) ;
    for(auto i:adj)
    {
        for(auto j:i.second)
        {
            indegree[j]++;
        }
    }

    //0 indegree walo ko add karo
    queue<int> q;
    for (int i = 1; i <= v; i++)
    {
        if(indegree[i] == 0)
        q.push(i);
    }
    

    //do bfs
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        //ans store
        ans.push_back(front);

        for(auto neighbour:adj[front])
        {
            indegree[neighbour]--;

            //queue insertion if indegree = 0
            if(indegree[neighbour] == 0)
            q.push(neighbour);
        }
    }
 
   return ans; 
}


int main()
{
     vector<vector<int>> edges = {{1,2},
                                  {1,3},
                                  {2,5},
                                  {3,5},
                                  {5,4}};
    vector<int> ans = topologicalSort(edges,5,5);
    for(auto i:ans)
    cout<<i<<" ";
    cout<<endl;
    return 0;
}