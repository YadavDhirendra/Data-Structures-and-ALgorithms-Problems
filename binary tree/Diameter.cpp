//Diameter of tree : Largest path bt any two end nodes
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

void BuildTreeLvlorder(node* &root){

    int data;
    cout<<"Enter the data : "<<endl;
    cin>>data;
    root = new node(data);
    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop();

        //left addition
        int leftdata;
        cout<<"Enter the data left to "<<temp->data<<endl;
        cin>>leftdata;

        if(leftdata != -1)
        {
            temp->left  = new node(leftdata);
            q.push(temp->left);
        }

        //right addition
        int rightdata;
        cout<<"Enter the data right to "<<temp->data<<endl;
        cin>>rightdata;

        if(rightdata != -1)
        {
            temp->right  = new node(rightdata);
            q.push(temp->right);
        }
    }
    
}

pair<int,int> diameterFast(node* root)      //logic of diameter and height mix to make T.C. O(n^2) to O(n)
{
    //base case
    if(root == NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> leftans = diameterFast(root->left);
    pair<int,int> rightans = diameterFast(root->right);

    int op1 = leftans.first; //diameter from left half
    int op2 = rightans.first;  //diameter from right half
    int op3 = leftans.second + rightans.second + 1; //diameter made by left + right height with root

    pair<int,int> ans;
    ans.first = max(op1 , max(op2,op3));
    
    ans.second = max(leftans.first,rightans.first) + 1; //same logic as height

    return ans;
}

int diameter(node* root)
{
    //base case
    if(root == NULL)
    return 0;

    return diameterFast(root).first;
}

int main()
{
    node* root ;
    BuildTreeLvlorder(root);
    cout<<"The diameter of given Tree is : "<<diameter(root)<<endl;
    return 0;
}