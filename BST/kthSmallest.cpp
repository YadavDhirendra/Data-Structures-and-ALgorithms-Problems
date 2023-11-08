//Kth smallest element in BST
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

node* BuildBST(node* &root,int d)
{
    //base case
    if(root == NULL)
    {
        root = new node(d);
        return root;
    }

    //left insertion
    if(root->data > d)
    root->left = BuildBST(root->left,d);

    //right insetion
    if(root->data < d)
    root->right = BuildBST(root->right,d);

    return root;

}

void takeinput(node* &root)
{
    int data;
    cout<<"Enter the data to create BST :"<<endl;
    cin>>data;

    while (data != -1)
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

int solve(node* root,int &i ,int k)//inorder traversal
{
    //base case
    if(root == NULL)
    return -1;

    //L
    int left = solve(root->left,i,k);
    
    if(left != -1)
    return left;

    //N
    i++;

    if(i == k)
    return root->data;

    //R
    return solve(root->right,i,k);

}

int kthSmallest(node* root,int k)
{   
    int i = 0;
    int ans = solve(root,i,k);
    return ans;
}

void inorder(node* root)
{
    //base case
    if(root == NULL)
    return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main()
{
    node* root = NULL;
    takeinput(root);
    levelordertraversal(root);
    cout<<"Inorder traversal :"<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Enter the value of k :"<<endl;
    int k;
    cin>>k;
    cout<<"The "<<k<<"th smallest value of BST is : "<<kthSmallest(root,k)<<endl;
    return 0;
}