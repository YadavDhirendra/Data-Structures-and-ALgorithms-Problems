//Vertical Travesal of a Binary Tree
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

vector<int> verticalOrder(node *root)
{
    map<int, map<int, vector<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;
    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();

        node *frontnode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontnode->data);

        if (frontnode->left)
            q.push(make_pair(frontnode->left, make_pair(hd - 1, lvl + 1)));

        if (frontnode->right)
            q.push(make_pair(frontnode->right, make_pair(hd + 1, lvl + 1)));
    }

    for (auto i : nodes)
    {
        for (auto j : i.second)
        {

            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
    
    return ans;
}

int main()
{
    node* root ;
    BuildTreelvlorder(root);
    vector<int> vert = verticalOrder(root);
    for (int i = 0; i < vert.size(); i++)
    {
        cout<<vert[i]<<" ";
    }
    cout<<endl;
    return 0;
}