//Smallest Range from K sorted List
//You are given 'K' lists containing non-negative integers.Each list has a size 'N' 
//and is sorted in non-decreasing order. You need to find the min length of a range 
//such that at leadt one element of each list must be included in that range.
//ex: In 3 lists [1 10 11], [2 3 20] and [5 6 12] then the [1 5] is the range
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int row;
    int col;

    Node(int d,int r,int c)
    {
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(Node* a,Node* b){
    return a->data > b->data;
    }
};

int kSorted(vector<vector<int>> &a,int k,int n)
{
    int mini = INT_MAX,maxi = INT_MIN;
    priority_queue<Node*,vector<Node*>, compare> minHeap;

    for (int  i = 0; i < k; i++)
    {
        int element = a[i][0];

        maxi = max(maxi,element);
        minHeap.push(new Node(element,i,0));
    }
    
    int start = mini, end = maxi;

    while (!minHeap.empty())
    {
        Node* temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        if(maxi - mini < end - start)
        {
            start = mini;
            end = maxi;
        }

        if(temp->col+1<n)
        {
            maxi = max(maxi,a[temp->row][temp->col+1]);
            minHeap.push(new Node(a[temp->row][temp->col+1],temp->row,temp->col));
        }
        else
        {
            break;
        }

    }
    return (end-start-1);
}

int main()
{
    vector<vector<int>> a = {{1,10,11},
                            {2,3,20},
                            {5,6,12}};
    cout<<"The smallest Range is : "<<kSorted(a,3,3)<<endl;
    return 0;
}