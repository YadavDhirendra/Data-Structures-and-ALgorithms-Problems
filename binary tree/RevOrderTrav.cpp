//Reversal order traversal
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
        left = right = NULL;
    }
};

void BuildlevelorderTree(node* &root)
{
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
    root = new node(data);
    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* frontnode = q.front();
        q.pop();

        //left addition
        int leftdata;
        cout<<"Enter the data left to "<<frontnode->data<<endl;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            frontnode->left = new node(leftdata);
            q.push(frontnode->left);
        }

        //right addition
        int rightdata;
        cout<<"Enter the data right to "<<frontnode->data<<endl;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            frontnode->right = new node(rightdata);
            q.push(frontnode->right);
        }
    }
    
}

void ReverselvlorderTraversal(node* root)
{
    //base case
    if(root == NULL)
    return;

    ReverselvlorderTraversal(root->left);
    ReverselvlorderTraversal(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node* root;
    BuildlevelorderTree(root);
    ReverselvlorderTraversal(root);
    return 0;
}