//Burning Tree
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

node *createParentMapping(node *root, int target, map<node *, node *> &nodeToParent)
{
    node *res = NULL;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *frontnode = q.front();
        q.pop();

        if (frontnode->data == target)
        {
            res = frontnode;
        }

        if (frontnode->left)
        {
            nodeToParent[frontnode->left] = frontnode;
            q.push(frontnode->left);
        }
        if (frontnode->right)
        {
            nodeToParent[frontnode->right] = frontnode;
            q.push(frontnode->right);
        }
    }
    return res;
}

int burntree(node *root, map<node *, node *> &nodeToParent)
{
    map<node *, bool> visited;
    queue<node *> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while (!q.empty())
    {
        bool flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            //process neighbouring nodes
            node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]];
            }
        }
        if(flag == 1)
        ans++;
    }
    return ans;
}

int minTime(node *root, int target)
{
    //algo.
    //step 1. Create nodeToParent mapping
    //step 2. find target node
    //step 3. burn the tree in min time

    int ans = 0;
    map<node *, node *> nodeToParent;
    node *targetNode = createParentMapping(root, target, nodeToParent);
    return burntree(targetNode,nodeToParent);
}

int main()
{
    node* root;
    BuildTreelvlordr(root);
    cout<<"Enter the target node :"<<endl;
    int target;
    cin>>target;
    cout<<"MIN time to burn above tree completely is : "<<minTime(root,target)<<endl;
    return 0;
}