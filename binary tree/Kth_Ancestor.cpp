//Kth Ancestor in a Binary Tree
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

//wapas aagye
node* solve(node* root,int k,int Node)
{
    //base case
    if(root == NULL)
    return NULL;

    if(root->data == Node)
    return root;

    node* leftans = solve(root->left,k,Node);
    node* rightans = solve(root->right,k,Node);

    if(leftans!=NULL && rightans == NULL)
    {
        k--;
        if(k<=0)
        {   //answer lock
            k = INT_MAX;
            return root;
        }
        return leftans;
    }
    if(leftans == NULL && rightans != NULL)
    {
        k--;
        if(k<=0)
        {   //answer lock
            k = INT_MAX;
            return root;
        }
        return rightans;
    }
    return NULL;
}

int kthAncestor(node* root,int k,int Node)
{

    node* ans = solve(root,k,Node);
    //base case
    if(ans == NULL || ans->data == Node)
    return -1;
    else
    return ans->data;
}

int main()
{
    node* root;
    BuildTreelvlordr(root);
    cout<<"Enter the value of k and node :"<<endl;
    int k,Node;
    cin>>k>>Node;
    cout<<"The "<<k<<"th ancestor of "<<Node<<" is : "<<kthAncestor(root,k,Node)<<endl;
    return 0;
}