//Merge 2 BST by approach 2
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = right = NULL;
    }
};

node* BuildBST(node* root,int d)
{
    //base case
    if(root == NULL)
    return root = new node(d);

    //right insertion
    if(root->data < d)
    root->right = BuildBST(root->right,d);

    //left insertion
    if(root->data > d)
    root->left = BuildBST(root->left,d);

    return root;
}

void takeinput(node* &root)
{
    int data;
    cout<<"Enter the data to create BST :"<<endl;
    cin>>data;

    while (data!=-1)
    {
        root = BuildBST(root,data);
        cin>>data;
    }
    
}

void levelordertraversal(node* root)
{
    cout<<"Printing BST :"<<endl;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node* front = q.front();
        q.pop();

        if(front == NULL)
        {
            cout<<endl;
            if(!q.empty())
            q.push(NULL);
        }
        else
        {
            cout<<front->data<<" ";

            //left insertion
            if(front->left)
            q.push(front->left);

            //right insertion
            if(front->right)
            q.push(front->right);
        }
    }
    
}

void convertSortedDLL(node* root,node* &head)
{
    //base case
    if(root == NULL)
    return ;

    convertSortedDLL(root->right,head);

    root->right = head;

    if(head != NULL)
    head->left = root;

    head = root;

    convertSortedDLL(root->left,head);
}

node* mergeLinkedList(node* &head1,node* &head2)
{
    node* head = NULL;
    node* tail = NULL;

    while (head1!=NULL && head2!=NULL)
    {
        if(head1->data<head2->data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
               head1->left = tail;
               tail = head1;
               head1 = head1->right;
            }
        }
        else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1!=NULL)
    {
        tail ->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    
    while (head2!=NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    
    return head;   
}

int countNodes(node* head)
{
    int cnt = 0;
    while (head!=NULL)
    {
        cnt++;
        head = head->right;
    }
return cnt;
}

node* sortedLLtoBST(node* &head,int n)
{
    //base case
    if(n <= 0 || head == NULL)
    return NULL;

    node* left = sortedLLtoBST(head,n/2);

    node* root = head;
    root->left = left;

    head = head->right;

    node* right = sortedLLtoBST(head,n-n/2-1);
    root->right = right;

    return root;
}

node* mergeBST(node* root1,node* root2)
{
    //step 1.convert BST into sorted DLL in-place
    node* head1 = NULL;
    convertSortedDLL(root1,head1);
    head1->left = NULL;

    node* head2 = NULL;
    convertSortedDLL(root2,head2);
    head2->left = NULL;

    //step 2.merge sorted LL
    node* head = mergeLinkedList(head1,head2);

    //step 3.convert DLL to BST
    node* root = sortedLLtoBST(head,countNodes(head));

    return root;
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