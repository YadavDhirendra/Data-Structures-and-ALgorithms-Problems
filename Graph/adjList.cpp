//Adjacency list of Graph
#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int> > adj;

    void addEdge(int u ,int v,int direction = 0)
    {
        //direction = 0 -> undirected
        //direction = 1 -> directed

        //create an edge
        adj[u].push_back(v);

        if(direction == 0)
        adj[v].push_back(u);
    }

    void printAdjList()
    {
        for(auto i:adj)
        {   
            cout<<i.first<<" -> ";
            int n = i.second.size();
            for(auto j:i.second){
            cout<<j;
            n--;
            if(n>0)
            cout<<" , ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n,m;
    cout<<"Enter the no. of nodes :"<<endl;
    cin>>n;

    cout<<"Enter the no. of edges :"<<endl;
    cin>>m;

    graph g;

    for (int i = 0; i < m; i++)
    {
        int u,v;//as edge represented in (x,y) for all x and y belongs to n
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.printAdjList();
    return 0;
}
