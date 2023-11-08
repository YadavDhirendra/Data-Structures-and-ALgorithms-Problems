//Lowest common Ancestor in BST
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

node* LCA(node* root,int n1,int n2)
{
    //base case
    if(root == NULL)
    return root;

    //if n1 and n2 both are > root->data then go into right part
    if(root->data < n1 && root->data < n2)
    return LCA(root->right,n1,n2);

    //if n1 and n2 both are < root->data then go into left part
    if(root->data > n1 && root->data > n2)
    return LCA(root->left,n1,n2);

    //if n1 > root->data and n2 < root->data or vice-versa then return root
    return root;

}

int main()
{
    node* root = NULL;
    takeinput(root);
    levelordertravesal(root);
    int n1,n2;
    cout<<"Enter the value of n1 and n2 :"<<endl;
    cin>>n1>>n2;
    cout<<"The LCA of "<<n1<<" and "<<n2<<" is : "<<LCA(root,n1,n2)->data<<endl;
    return 0;
}