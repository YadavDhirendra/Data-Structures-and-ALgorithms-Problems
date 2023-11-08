//Middle element in Linked List by Approach 2(slow and fast)
//fast travel 2x times than slow
//so if fast taraversed whole LL then slow will be at mid,That's the concept
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next; 
    Node(int d){
        data = d;
        next = NULL;    
    }
};

void InsertAtHead(Node* &head,int d){

    //new node to insert
    Node* newnode = new Node(d);

    //empty list
    if(head == NULL)
    {
        head = newnode;
        return;     
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

void print(Node* head)
{
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* MidLL2(Node* head)
{
    //empty list or having 1 element
    if(head == NULL || head->next ==NULL)
    return head;
    
    Node* slow = head;
    Node* fast = head->next;
    while (fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        fast = fast->next;

        slow = slow->next;
    }
    
    return slow;
}

int main()
{
     Node* node1 = new Node(4);
    Node* head = node1;
    InsertAtHead(head,3);
    InsertAtHead(head,2);
    InsertAtHead(head,1);
    print(head);
    cout<<"The Middle element of given linked list is "<<MidLL2(head)->data<<endl;
    return 0;
}