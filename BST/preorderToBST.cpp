//Preorder to BST
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

node* solve(vector<int> &preorder,int maxi,int &i)
{

    //base case
    if(i > preorder.size()-1)
    return NULL;

    if(preorder[i]>maxi )
    return NULL;

    node* root = new node(preorder[i++]);
    root->left = solve(preorder,root->data,i);
    root->right = solve(preorder,maxi,i);

    return root;

}

node* preorderToBST(vector<int> &preorder)
{
    int maxi = INT_MAX;
    // int mini = INT_MIN;
    int i = 0;
    return solve(preorder,maxi,i);
}

int main()
{
    vector<int> preorder;
    cout<<"Enter the preorder values of BST :"<<endl;
    int data ;
    cin>>data;
    while (data!=-1)
    {
        preorder.push_back(data);
        cin>>data;
    }
    node *root = preorderToBST(preorder);
    levelordertravesal(root);
    return 0;
}