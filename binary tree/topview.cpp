//Top view of Binary Tree just like vertical order
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

vector<int> topview(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

   map<int,int> topnodes;
   queue<pair<node*,int>> q;

   q.push(make_pair(root,0));

   while (!q.empty())
   {
       pair<node*,int> temp = q.front();
       q.pop();

       node* frontnode= temp.first;
       int hd = temp.second;

       //if one value is present for HD,then dont insert
       if(topnodes.find(hd) == topnodes.end())
       topnodes[hd] = frontnode->data;

       //node addition
       if(frontnode->left)
       q.push(make_pair(frontnode->left,hd-1));

       if(frontnode->right)
       q.push(make_pair(frontnode->right,hd+1));

   }
   
    for(auto i:topnodes)
    {
        ans.push_back(i.second);//since i has only one element
    }
    return ans;
}

int main()
{
    node* root;
    BuildTreelvlorder(root);
    vector<int> top = topview(root);
    for (int i = 0; i < top.size(); i++)
    {
        cout<<top[i]<<" ";
    }
    cout<<endl;
    return 0;
}