//Bottom view of Binary tree just like tpo view just remove one element condition
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

vector<int> bottomView(node* root)
{
    vector<int> ans;
    if(root== NULL)
    return ans;

    map<int,int> topnodes;
    queue<pair<node* ,int>> q;//here int -> hd
    q.push(make_pair(root,0));

    while (!q.empty())
    {
        pair<node*,int> temp = q.front();
        q.pop();

        node* frontnode = temp.first;
        int hd = temp.second;

        topnodes[hd] = frontnode->data;

        //node addition
        if(frontnode->left)
        q.push(make_pair(frontnode->left,hd-1));

        if(frontnode->right)
        q.push(make_pair(frontnode->right,hd+1));
        
    }
    
    for(auto i:topnodes)
    {
        ans.push_back(i.second);
    }
    return ans;
}

int main()
{
     node* root;
    BuildTreelvlorder(root);
    vector<int> bot = bottomView(root);
    for (int i = 0; i < bot.size(); i++)
    {
        cout<<bot[i]<<" ";
    }
    cout<<endl;
    return 0;
}