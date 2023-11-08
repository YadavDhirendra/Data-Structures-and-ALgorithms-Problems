//Predecessor ans successor in BST
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

node *BuildBST(node *root, int d)
{
    //base case
    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    //right insertion
    if (root->data < d)
        root->right = BuildBST(root->right, d);

    //left insertion
    if (root->data > d)
        root->left = BuildBST(root->left, d);

    return root;
}

void takeinput(node *&root)
{
    int data;
    cout << "Enter the data to create BST :" << endl;
    cin >> data;

    while (data != -1)
    {
        root = BuildBST(root, data);
        cin >> data;
    }
}

void levelordertraversal(node *root)
{
    cout << "Printing BST :" << endl;
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << front->data << " ";

            //left insertion
            if (front->left)
                q.push(front->left);

            //right insertion
            if (front->right)
                q.push(front->right);
        }
    }
}

pair<int, int> predecessorSuccessor(node *root, int key)
{
    int pred, succ;
    //find key node
    node *temp = root;
    while (temp->data != key)
    {
        if (temp->data < key)
        {
            pred = temp->data;//if temp is leaf node then we have to store pred from prev values
            temp = temp->right;
        }

        if (temp->data > key)
        {
            succ = temp->data;//if temp is leaf node then we have to store succ from the prev values
            temp = temp->left;
        }
    }


    //pred(max of left subtree)
    node *leftTree = temp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    //succ(min of right subtree )
    node *rightTree = temp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred, succ};
}

int main()
{
    node *root = NULL;
    takeinput(root);
    levelordertraversal(root);
    cout << "enter the value of key :" << endl;
    int key;
    cin >> key;
    cout << "The predecessor of " << key << " is " << predecessorSuccessor(root, key).first << " and Successor is " << predecessorSuccessor(root, key).second << endl;
    return 0;
}