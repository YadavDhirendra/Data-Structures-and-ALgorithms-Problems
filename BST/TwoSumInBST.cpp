//You have been given a BST and a target value.You need to find out whether there exists a pair of node values in the BST,such that their sum is equal to the target value
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

node* BuildBST(node* root,int d)
{
    //base case
    if(root == NULL)
    {
        return root = new node(d);
    }

    if(root->data < d)
    root->right = BuildBST(root->right,d);

    if(root->data > d)
    root->left = BuildBST(root->left,d);

    return root;
}

void takeinput(node* &root)
{
    int data;
    cout<<"Enter the data to create BST :"<<endl;
    cin>>data;
    while (data!=-1)
    {
        root = BuildBST(root,data);
        cin>>data;
    }
    
}

void levelordertravesal(node* root)
{
    cout<<"Printing BST :"<<endl;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* front = q.front();
        q.pop();

        if(front == NULL)
        {
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        }
        else
        {
            cout<<front->data<<" ";

            if(front->left)
            q.push(front->left);

            if(front->right)
            q.push(front->right);
        }
    }
}

void inorder(node* root,vector<int> &in)
{
    //base case
    if(root == NULL)
    return;

    //L
    inorder(root->left,in);
    //N
    in.push_back(root->data);
    //R
    inorder(root->right,in);

}

bool twoSumInBST(node* root,int target)
{
    vector<int> in;
    inorder(root,in);
    //Now in contains sorted values of BST

    int i = 0 , j = in.size()-1;

    while (i<j)
    {
        int sum = in[i] + in[j];

        if(sum == target)
        return true;

        if(sum > target)
        j--;//by dec j in[j] decs and sum also dec

        if(sum < target)
        i++;//by inc i in[i] inc and sum also inc
    }
    
}

int main()
{
    node* root = NULL;
    takeinput(root);
    levelordertravesal(root);
    cout<<"Enter the value of target :"<<endl;
    int target;
    cin>>target;
    if(twoSumInBST(root,target))
    cout<<"yes sum of nodes make target in given BST"<<endl;
    else
    cout<<"Sorry not found"<<endl;
    return 0;
}