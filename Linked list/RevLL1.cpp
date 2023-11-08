//Reverse Linked List 
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
    Node *newNode = new Node(d);

    //empty list
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void print(Node* &head)
{
    Node* temp = head;
    while (temp!=NULL)
    {
        
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* RevLL1(Node* &head)
{
    Node* prev = NULL;
    Node* curr = head;
    while (curr!=NULL)
    {
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

int main()
{
    Node* node1 = new Node(3);
    Node* head = node1;
    InsertAtHead(head,5);
    InsertAtHead(head,7);
    InsertAtHead(head,9);
    print(head);
    //reverse head
    Node* revhead = RevLL1(head);
    print(revhead);
    return 0;
}