//Flatten BST in a sorted list
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

void inorder(node* root,vector<int> &ans)
{
    //base case
    if(root == NULL)
    return;

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

node* flattenBST(node* root)
{   
    //step 1.Store inorder -> sorted values
    vector<int> in;
    inorder(root,in);
    //Now in contains all sorted values of BST

    node* newRoot = new node(in[0]);
    node* curr = newRoot;

    //2nd step(make list)
    for (int i = 1; i < in.size(); i++)
    {   
        node* temp = new node(in[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
        
    }
    
    //3rd step (pointing last node to NULL)
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

void print(node* temp)
{
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}
int main()
{
    node* root = NULL;
    takeinput(root);
    levelordertravesal(root);
    node* flat = flattenBST(root);
    print(flat);
    return 0;
}