//Sum of the longest bloodline of a tree(sum of nodes on the longest path from root to leaf node)
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

void solve(node *root, int len, int &maxlen, int sum, int &maxSum)
{
    //base case
    if(root == NULL)
    {
        if(len>maxlen)
        {
            maxlen = len;
            maxSum = sum;
        }
        else if(len == maxlen)
        {
            maxSum = max(maxSum,sum);
        }
        return;
    }

    sum = sum + root->data;
    solve(root->left,len+1,maxlen,sum,maxSum);
    solve(root->right,len+1,maxlen,sum,maxSum);

}

int sumofLongRootToLeafPath(node *root)
{
    int len = 0;
    int maxlen = 0;

    int sum = 0;
    int maxSum = INT_MIN;
    solve(root,len,maxlen,sum,maxSum);
    return maxSum;
}

int main()
{
    node* root;
    BuildTreelvlordr(root);
    cout<<"The sum of longest path of given binary tree is "<<sumofLongRootToLeafPath(root)<<endl;;
    return 0;
}