//Creation of Binary Tree
#include <bits/stdc++.h>
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
        left = NULL;
        right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "Enter the data :" << endl;
    cin >> data;

    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrdertraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {   //purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())//queue still has child nodes
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void inorder(node* root)//Inorder : LNR
{
    //base case
    if(root == NULL)
    return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root)//preorder : NLR
{
    //base case
    if(root == NULL)
    return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root)//postorder : LRN
{
    //base case
    if(root == NULL)
    return ;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

node* buildFromLevelOrder(node* root)
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

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1)
        {
            temp ->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1)
        {
            temp ->right = new node(rightdata);
            q.push(temp->right);
        }

    }
    return root;
}

int main()
{
    node *root = NULL;
    root = buildFromLevelOrder(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrdertraversal(root);
    cout<<endl;
    cout<<"Inorder traversal : "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"preorder traversal : "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"postorder traversal : "<<endl;
    postorder(root);
    cout<<endl;
    return 0;
}