//Find the articulation pts in any graph .
//Articulation pts are that pts which on removing divide the graph into components
//similar to bridge removal problem
#include<bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int> > &adj,int u ,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void APUtil(int node,int &parent,int &timer,vector<vector<int> > &adj,vector<int> &disc,vector<int> &low,vector<bool> &visited,vector<bool> &APT)
{   
    int child = 0;//if root has more than 1 child then it will be also AP
    visited[node] = 1;
    low[node] = disc[node] = timer++;

    for(auto nbr : adj[node])
    {   
        
        if(nbr == parent)
        continue;
        if(!visited[nbr]){
        child++;
        APUtil(nbr,node,timer,adj,disc,low,visited,APT);
        //update low[node] if nbr's low is updated
        low[node] = min(low[node],low[nbr]);

        //check for articulation pt.
        //here it means that there is single path from node to nbr if we remove node then it will divided into comp.
        if(low[nbr] >= disc[node] && parent!=-1)
        APT[node] = true;
        }
        else
        {
            //back edge
            low[node] = min(low[node],disc[nbr]);
        }
    }
    //check if root of dfs tree has more than one child
    if(parent == -1 && child>1)
    APT[node] = 1;
}

void AP(vector<vector<int> > adj,int v)
{
    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    vector<bool> visited(v,false);
    vector<bool> APT(v,false);

    int parent = -1;
    int timer  = 0;

    //do dfs
    for(int i = 0; i<v; i++)
    {
        if(!visited[i])
        APUtil(i,parent,timer,adj,disc,low,visited,APT);
    }

    //print APs
    for(int i = 0; i<v; i++)
    {
        if(APT[i])
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
cout<<"Articulation pts :\n";
int v = 5;
int e = 6;
vector< vector<int> > adj(v);
addedge(adj,1,0);
addedge(adj,0,4);
addedge(adj,1,4);
addedge(adj,2,3);
addedge(adj,2,4);
addedge(adj,3,4);
AP(adj,v);
return 0;
}