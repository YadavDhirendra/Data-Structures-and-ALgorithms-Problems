//Maximum sum of non-adjacent nodes
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

pair<int,int> solve(node* root)
{
    //base case
    if(root == NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = solve(root->left);
    pair<int,int> right = solve(root->right);

    pair<int,int> res;
    
    //including root
    res.first = root->data + left.second + right.second;
    //excluding root
    res.second = max(left.first,left.second) + max(right.first,right.second);

    return res;

}

int getMaxSum(node* root)
{
    pair<int,int> res = solve(root);

    int ans = max(res.first,res.second);
    return ans;
}

int main()
{
    node* root;
    BuildTreelvlordr(root);
    cout<<"The max sum of non-adjacent nodes is : "<<getMaxSum(root)<<endl;
    return 0;
}