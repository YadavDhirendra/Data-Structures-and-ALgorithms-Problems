//Given a Binary Tree with N number of nodes,check if that input tree is bst or not.if yes return true else false
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left ;
    node* right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* BuildBST(node* &root,int d)
{   
    //base case
    if(root == NULL)
    {
        root = new node(d);
        return root;
    }

    //left insertion
    if(root->data<d)
    root->right = BuildBST(root->right,d);

    //right insertion
    if(root->data>d)
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

bool isBST(node* root,int mini,int maxi)
{
    //base case
    if(root == NULL)
    return true;

    if(root->data>mini && root->data<maxi)
    {
        bool left = isBST(root->left,mini,root->data);
        bool right = isBST(root->right,root->data,maxi);
        return left && right;
    }
    else
    return false;  
}

bool validateBST(node* root)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    return isBST(root,mini,maxi);
}

void levelordertraversal(node* root)
{   
    cout<<"Printing Tree :"<<endl;
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

int main()
{
    node* root = NULL;
    takeinput(root);
    levelordertraversal(root);
    if(validateBST(root))
    cout<<"Yes Given tree is BST"<<endl;
    else
    cout<<"Sorry given tree is not BST"<<endl;
    return 0;
}