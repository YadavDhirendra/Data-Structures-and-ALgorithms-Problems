//Is Binary Tree Heap(max)
//Necessary conditions : 1.CBT(Complete Binary Tree)
//2.Maxorder follow
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};

void BuildTree(node* &root)
{
    int data;
    cout<<"Enter the data :"<<endl;
    cin>>data;
    root = new node(data);
    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* front = q.front();
        q.pop();

        //left insertion
        cout<<"Enter the data left to "<<front->data<<endl;
        cin>>data;
        if(data != -1)
        {
            front->left = new node(data);
            q.push(front->left);
        }

        //right insertion
        cout<<"Enter the data right to "<<front->data<<endl;
        cin>>data;
        if(data != -1)
        {
            front->right = new node(data);
            q.push(front->right);
        }
    }
    
}

void inorder(node* root)
{
    //base case
    if(root == NULL)
    return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int CountNodes(node* root)
{
    //base case
    if(root == NULL)
    return 0;

    int ans = 1 + CountNodes(root->left) + CountNodes(root->right);
    return ans;

}

bool isCBT(node* root,int index,int cnt)
{
    if(root == NULL)
    return true;

    if(index >= cnt)
    return false;
    else{
        bool left = isCBT(root->left,2*index+1,cnt);
        bool right = isCBT(root->right,2*index+2,cnt);
        return left&&right;
    }
}

bool isMaxorder(node* root)
{
    //leaf node
    if(root->left==NULL && root->right == NULL)
    return true;

    if(root->right == NULL)
    {
        return (root->data > root->right->data);
    }
    else
    {
        bool left = isMaxorder(root->left);
        bool right = isMaxorder(root->right);
        bool curr = (root->data>root->left->data && root->data>root->right->data);

        if(left && right && curr)
        return true;
        else
        return false;
    }

}

bool isHeap(node* root)
{
    int index = 0;
    int totalnodes = CountNodes(root);
    
    if(isCBT(root,index,totalnodes) && isMaxorder(root))
    return true;
    else
    return false;
}

int main()
{
    node* root = NULL;
    BuildTree(root);
    cout<<"Printing Inorder :"<<endl;
    inorder(root);
    cout<<endl;
    if(isHeap(root))
    cout<<"Given tree is Heap"<<endl;
    else
    cout<<"Sorry! Given Tree is'nt Heap"<<endl;
    return 0;
}