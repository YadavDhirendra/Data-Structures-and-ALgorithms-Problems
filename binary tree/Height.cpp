//height of a binary tree : Longest path bt any leaf node to root
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void BuildtreeLevelorder(node* &root)
{
    int data;
    queue<node*> q;
    cout<<"Enter the data :"<<endl;
    cin>>data;
    root = new node(data);

    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();
        //left addition
        int leftdata;
        cout<<"Enter the data left to "<<temp->data<<endl;
        cin>>leftdata;
        if(leftdata !=-1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        //right addition
        int rightdata;
        cout<<"Enter the data right to "<<temp->data<<endl;
        cin>>rightdata;
        if(rightdata !=-1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
    
}

int height(node* root)
{
    //base case
    if(root == NULL)
    return 0;

    int left1 = height(root->left);
    int right1 = height(root->right);

    int ans = max(left1,right1) + 1;

    return ans;
}


int main()
{
    node* root = NULL;
    BuildtreeLevelorder(root);
    cout<<"The height of given tree is : "<<height(root)<<endl;
    return 0;
}