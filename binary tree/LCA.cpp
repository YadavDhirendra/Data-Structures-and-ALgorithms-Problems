//Lowest Common Ancestor in a Binary Tree
#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void BuildTreelvlordr(node *&root)
{
    int data;
    cout << "Enter the data" << endl;
    cin >> data;
    root = new node(data);
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *frontnode = q.front();
        q.pop();

        //left addition
        int leftdata;
        cout << "Enter the data left to " << frontnode->data << endl;
        cin >> leftdata;
        if (leftdata != -1)
        {
            frontnode->left = new node(leftdata);
            q.push(frontnode->left);
        }

        //right addition
        int rightdata;
        cout << "Enter the data right to " << frontnode->data << endl;
        cin >> rightdata;
        if (rightdata != -1)
        {
            frontnode->right = new node(rightdata);
            q.push(frontnode->right);
        }
    }
}

node* lca(node* root,int n1,int n2)
{
    //base case
    if(root == NULL)
    return NULL;

    if(root->data == n1 || root->data == n2)
    return root;

    node* leftans = lca(root->left,n1,n2);
    node* rightans = lca(root->right,n1,n2);

    if(leftans == NULL && rightans!=NULL)
    return rightans;
    else if(leftans!=NULL && rightans == NULL)
    return leftans;
    else if(leftans!=NULL && rightans!=NULL)
    return root;
    else
    return NULL;
}

int main()
{
    node* root;
    BuildTreelvlordr(root);
    int n1,n2;
    cout<<"Enter the value of n1 and n2 :"<<endl;
    cin>>n1>>n2;
    cout<<"The lca of "<<n1<<" ans "<<n2<<" is : "<<lca(root,n1,n2)->data<<endl;
    return 0;
}