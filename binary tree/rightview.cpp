//Right view of Binary tree just like left view interchange the recursive calls right first then left
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

void solve(node *root, vector<int> &ans, int level)
{
    //base case
    if (root == NULL)
        return;

    //we entered into a new level
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}

vector<int> rightview(node *root)
{
    vector<int> ans;
    solve(root,ans,0);
    return ans;
}

int main()
{
    node* root;
    BuildTreelvlorder(root);
    vector<int> right = rightview(root);
    for (int i = 0; i < right.size(); i++)
    {
        cout<<right[i]<<" ";
    }
    cout<<endl;
    return 0;
}