//Middle element of Linked List
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

int MidLL(Node* head)
{
    int len = 0;
    Node* temp = head;
    while (temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    temp = head;
    int len1 = len/2;
    for (int i = 1; i < len1+1; i++)
    {
        temp = temp->next;
    }
    
    return temp->data;
    
}

int main()
{
     Node* node1 = new Node(4);
    Node* head = node1;
    InsertAtHead(head,3);
    InsertAtHead(head,2);
    InsertAtHead(head,1);
    print(head);
    cout<<"The Middle element of given linked list is "<<MidLL(head)<<endl;
    return 0;
}