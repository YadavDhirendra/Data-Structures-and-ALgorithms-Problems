//Flatten a binary tree into Linked List in O(1) S.C. (By Morris Traversal)
//Algo : step 1.start loop until curr becomes NULL,Here curr = root
//step 2.Check if curr->left exists.If exists make prev = curr->left
//step 3.start loop until the prev->right becomes NULL
//step 4.Now make prev->right = curr->right and curr->right = curr->left
//step 5.Now make curr = curr->right and curr->left = NULL
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        data = d;
        left = right = NULL;    
    }
};

void BuildTreelvlorder(node* &root)
{
    int data;
    cout<<"Enter the data :"<<endl;
    cin>>data;
    root = new node(data);
    queue<node* > q;
    q.push(root);

    while (!q.empty())
    {
        node* frontnode = q.front();
        q.pop();

        //left addition
        int leftdata;
        cout<<"Enter the data left to "<<frontnode->data<<endl;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            frontnode->left = new node(leftdata);
            q.push(frontnode->left);
        }

        //right addition
        int rightdata;
        cout<<"Enter the data right to "<<frontnode->data<<endl;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            frontnode->right = new node(rightdata);
            q.push(frontnode->right);
        }
    }
    
}

node* flatten(node* root)
{
    node* curr = root;
    while (curr!=NULL)
    {
        if(curr->left)
        {
            node* prev = curr->left;
            while(prev->right)
            prev = prev->right;

            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    return root;
}

void print(node* temp)
{
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

int main()
{
    node* root;
    BuildTreelvlorder(root);
    node* flat = flatten(root);
    print(flat);
    return 0;
}