//Given a binary tree ans an integer K.Find the no. of paths in the tree which have their sum equal to K.
//A path may start from any node and end at any node in the downward direction
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

void solve(node* root,int k,int &count,vector<int> path)
{

    //base case
    if(root == NULL)
    return;

    path.push_back(root->data);

    //left
    solve(root->left,k,count,path);

    //right
    solve(root->right,k,count,path);

    //check for k sum
    int size = path.size();
    int sum = 0;
    for (int i = size-1; i >= 0; i--)
    {
        sum += path[i];
        if(sum == k)
        count++;
    }
    
    //backtracking
    path.pop_back();
}

int KSumPaths(node* root,int k)
{
    vector<int> path;
    int count = 0;
    solve(root,k,count,path);
    return count;

}

int main()
{
    node* root;
    BuildTreelvlordr(root);
    int k;
    cout<<"Enter the value of k "<<endl;
    cin>>k;
    cout<<"K sum paths : "<<KSumPaths(root,k)<<endl;
    return 0;
}