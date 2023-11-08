//Normal BST to Balanced BST
//A Balanced BST is defined as a BST, in which the height of two subtrees of evry node differs no more than 1.
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

void levelordertraversal(node* root)
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

void inorder(node* root,vector<int> &ans)
{
    //base case
    if(root == NULL)
    return;

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

node* inorderToBST(int s,int e,vector<int> in)
{
    //base case
    if(s>e)
    return NULL;

    int mid = s + (e-s)/2;

    node* root = new node(in[mid]);
    root->left = inorderToBST(s,mid-1,in);
    root->right = inorderToBST(mid+1,e,in);

    return root;
}

node* balancedBST(node* root)
{
    vector<int> in;
    //store inorder -> sorted values
    inorder(root,in);

    return inorderToBST(0,in.size()-1,in);
}

int main()
{
    node* root = NULL;
    takeinput(root);
    levelordertraversal(root);
    node* newRoot = balancedBST(root);
    levelordertraversal(newRoot);
    return 0;
}