//Boundary Traversal of Binary Tree
//Given a Binary Tree,find its Boundary Travesal. The traversal should be in following
//order:
//1.Leaf boundary nodes : defined as the path from the root to the left-most node
//2.Leaf nodes : All the leaf nodes except for the ones that are part of left or
//right boundary.
//Reverse right boundary nodes : defined as the path from the right-most node to the root.
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
        left = right = NULL;
    }
};

void BuildTreelvlorder(node *&root)
{
    int data;
    cout << "Enter the data :" << endl;
    cin >> data;
    root = new node(data);
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        //left addition
        int leftdata;
        cout << "Enter the data left to " << temp->data << endl;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        //right addition
        int rightdata;
        cout << "Enter the data right to " << temp->data << endl;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

void traversalleft(node *root, vector<int> &ans)
{
    //base case
    if (root == NULL || root->left == NULL && root->right == NULL)
        return;

    ans.push_back(root->data);

    if (root->left)
        traversalleft(root->left, ans);
    else
        traversalleft(root->right, ans);
}

void traversalleaf(node *root, vector<int> &ans)
{
    //base case
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return ;
    }

    traversalleaf(root->left,ans);
    traversalleaf(root->right,ans);
}

void traversalright(node* root,vector<int> &ans)
{
    //base case
    if(root == NULL || root->left == NULL && root->right == NULL)
    return;

    if(root->right)
    traversalright(root->right,ans);
    else
    traversalright(root->left,ans);

    //backtracking to store in rev order
    ans.push_back(root->data);

}

vector<int> boundaryTraversal(node *root)
{
    vector<int> ans;
    if(root == NULL)
    return ans;

    ans.push_back(root->data);

    //leftpart print/store
    traversalleft(root->left,ans);

    //traverse leaf nodes
    traversalleaf(root,ans);
    // traversalleaf(root->right,ans);

    //right part print/store
    traversalright(root->right,ans);
}

int main()
{
    node *root;
    BuildTreelvlorder(root);
    vector<int> bound = boundaryTraversal(root);
    for (int i = 0; i < bound.size(); i++)
    {
        cout<<bound[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}