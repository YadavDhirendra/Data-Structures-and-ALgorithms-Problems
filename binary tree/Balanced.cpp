//Check for Balanced Tree
//Given a binary tree , find if its ht balanced or not.
//A tree is height balanced if diff bt hts of left and right subtrees is not more than one
//for all nodes of tree
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

void Buildtreelvlorder(node *&root)
{

    int data;
    cout << "Enter the data : " << endl;
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

pair<bool, int> CheckBalancedFast(node *root)
{
    //base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<bool, int> leftans = CheckBalancedFast(root->left);
    pair<bool, int> rightans = CheckBalancedFast(root->right);

    bool left1 = leftans.first;
    bool right1 = rightans.first;

    bool diff = abs(leftans.second - rightans.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(leftans.second, rightans.second) + 1;
    if (left1 && right1 && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

bool CheckBalanced(node *root)
{   
    if(root == NULL)
    return true;

    return CheckBalancedFast(root).first;
}
int main()
{
    node *root;
    Buildtreelvlorder(root);
    if(CheckBalanced(root))
    cout<<"Given tree is balanced"<<endl;
    else
    cout<<"Sorry! Given tree is not balanced"<<endl;
    return 0;
}
