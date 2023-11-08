//Binary Search Tree Implementation
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

node *insertIntoBST(node *&root, int data)
{
    //base case
    if (root == NULL)
    {
        root = new node(data);
        return root;
    }

    //right insertion
    if (data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }

    //left insertion
    if (data < root->data)
    {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
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
        node *frontnode = q.front();
        q.pop();

        if (frontnode == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << frontnode->data << " ";

            if (frontnode->left)
                q.push(frontnode->left);

            if (frontnode->right)
                q.push(frontnode->right);
        }
    }
}

void inorder(node *root)
{
    //base case
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    //base case
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    //base case
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

node *minVal(node *root)
{
    //base case
    if(root == NULL)
    return root;

    if (root->left == NULL )
        return root;

    return minVal(root->left);
}

node *maxVal(node *root)
{
    //base case
    if (root == NULL)
        return root;

    if ( root->right == NULL)
        return root;

    return maxVal(root->right);
}

bool searchBST(node *root, int x)
{
    //base case
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;

    if (x < root->data)
        return searchBST(root->left, x);
    else if (x > root->data)
        return searchBST(root->right, x);

    return false;
}

node *deletefromBST(node *root, int val)
{
    //base case
    if (root == NULL)
        return root;

    if (root->data == val)
    {
        //0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        //1 child

        //left child
        if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deletefromBST(root->right, mini);
        }
    }

    if (val > root->data)
    { //left part me jao
        root->right = deletefromBST(root->right, val);
        return root;
    }
    if (val < root->data)
    { //right part me jao
        root->left = deletefromBST(root->left, val);
        return root;
    }
}



int main()
{
    node *root = NULL;
    cout << "Enter the data to create BST :" << endl;
    takeInput(root);
    levelordertraversal(root);
    cout << "Inorder traversal :" << endl;
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal :" << endl;
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal :" << endl;
    postorder(root);
    cout << endl;
    cout << "Min value of BST is : " << minVal(root)->data << endl;
    cout << "Max value of BST is : " << maxVal(root)->data << endl;

    //searching
    cout << "Enter the element to search : " << endl;
    int x;
    cin >> x;
    if (searchBST(root, x))
        cout << "Element found.." << endl;
    else
        cout << "Sorry! Element not found.." << endl;

    //deletion
    cout << "Enter the value to delete : " << endl;
    cin >> x;
    root = deletefromBST(root, x);
    levelordertraversal(root);
    cout << "Inorder traversal :" << endl;
    inorder(root);
    cout << endl;
    cout << "Preorder Traversal :" << endl;
    preorder(root);
    cout << endl;
    cout << "Postorder Traversal :" << endl;
    postorder(root);
    cout << endl;
    cout << "Min value of BST is : " << minVal(root)->data << endl;
    cout << "Max value of BST is : " << maxVal(root)->data << endl;
    
   int cnt = 0;
   countLeaves(root,cnt);
   cout<<"No. of leaves in BT is : "<<cnt<<endl;
   
    return 0;
}