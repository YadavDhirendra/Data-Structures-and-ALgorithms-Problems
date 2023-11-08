//Merge K sorted arrays
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    int i;
    int j;

    node(int data,int row,int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)//O(n*k) algo
{
    priority_queue<node*,vector<node*> ,compare> minHeap;
    vector<int> ans;

    //Step 1.Saare arrays k first element insert h
    for (int i = 0; i < k; i++)
    {
        node* temp = new node(kArrays[i][0],i,0);
        minHeap.push(temp);
    }
    
    //step 2.
    while (minHeap.size()>0)
    {
       node* temp = minHeap.top();
       minHeap.pop();
       ans.push_back(temp->data);

       int i = temp->i;
       int j = temp->j;

       if(j+1<kArrays[i].size())
       {
           node* next = new node(kArrays[i][j+1],i,j+1);
           minHeap.push(next);
       }
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1,2,3},
                                {7,8,9},
                                {11,12,13}};
    int k  = 3;
    vector<int> sorted = mergeKSortedArrays(arr,k);
    for (int i = 0; i < sorted.size(); i++)
    {
        cout<<sorted[i]<<" ";
    }cout<<endl;
    
    return 0;
}