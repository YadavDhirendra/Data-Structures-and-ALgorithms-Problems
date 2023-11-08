//Zig Zag Tree Travel
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

vector<int> ZigZag(node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;

    queue<node *> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        for (int i = 0; i < size; i++)
        {

            node *frontnode = q.front();
            q.pop();
            //level process
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontnode->data;

            //node addition
            if (frontnode->left)
                q.push(frontnode->left);

            if (frontnode->right)
                q.push(frontnode->right);
        }
        for (auto i : ans)
        {
            result.push_back(i);
        }
        //direction change kr do
        leftToRight = !leftToRight;
    }
    return result;
}

int main()
{
    node *root;
    BuildTreelvlorder(root);
    vector<int> zigzag = ZigZag(root);
    for (int i = 0; i < zigzag.size(); i++)
    {
        cout << zigzag[i] << " ";
    }
    cout << endl;
    return 0;
}