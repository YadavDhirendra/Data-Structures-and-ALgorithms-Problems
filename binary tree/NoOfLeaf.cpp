//no. of leaf nodes in a binary tree
#include<bits/stdc++.h>
using namespace std;

class node{
    public :
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* buildtreefromLevelorder(node* root)
{
    queue<node*> q;
    int data;
    cout<<"Enter the data :"<<endl;
    cin>>data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"Enter the left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter the right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
    return root;
}

void levelordertraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);
        }
    }
    
}

void inorder(node* root,int &count){//Inorder : LNR

    //base case
    if(root == NULL)
    return ;

  
    inorder(root->left,count);
    
    if(root->left == NULL && root->right == NULL)
    count++;

    inorder(root->right,count);

}


int noOfLeaf(node* root)
{
    int count = 0;
    inorder(root,count);
    return count;
}
int main()
{
    node* root;
    root = buildtreefromLevelorder(root);
    levelordertraversal(root);
    cout<<"No. of leaf nodes : "<<noOfLeaf(root)<<endl;
    return 0;
}