//Merge 2 BST
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

node *BuildBST(node *&root, int d)
{
    //base case
    if (root == NULL)
    {
        return root = new node(d);
    }

    //right insertion
    if (root->data < d)
        root->right = BuildBST(root->right,d);

    //Left insertion
    if (root->data > d)
        root->left = BuildBST(root->left,d);

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

void inorder(node *root, vector<int> &ans)
{
    //base case
    if (root == NULL)
        return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> mergeArrays(vector<int> bst1, vector<int> bst2)
{
    int i = 0, j = 0, k = 0;
    int n1 = bst1.size();
    int n2 = bst2.size();
    vector<int> ans(n1 + n2);
    while (i < bst1.size() && j < bst2.size())
    {
        if (bst1[i] < bst2[j])
            ans[k++] = bst1[i++];
        else
            ans[k++] = bst2[j++];
    }

    while (i < n1)
    {
        ans[k++] = bst1[i++];
    }

    while (j < n2)
    {
        ans[k++] = bst2[j++];
    }
    return ans;
}

node *inorderToBST(vector<int> inval, int s, int e)
{
    //base case
    if(s>e)
    return NULL;

    int mid = s + (e-s)/2;

    node* root = new node(inval[mid]);
    root->left = inorderToBST(inval,s,mid-1);
    root->right = inorderToBST(inval,mid+1,e);
    return root;
}

node *mergeBST(node *root1, node *root2)
{
    //step 1.Make inorder->sorted arrays of both BST
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    //step 2.Merge both sorted arrays
    vector<int> mergedArray = mergeArrays(bst1, bst2);
    

    //step 3.Now make Bst from inorder
    return inorderToBST(mergedArray,0,mergedArray.size()-1);
    
}

int main()
{
    node *root1 = NULL;
    node *root2 = NULL;
    takeinput(root1);
    takeinput(root2);
    levelordertraversal(root1);
    levelordertraversal(root2);
    node* root = mergeBST(root1,root2);
    levelordertraversal(root);
    return 0;
}