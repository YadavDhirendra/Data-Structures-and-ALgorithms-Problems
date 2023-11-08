//Doubly Linked List
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    Node *prev;
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        int value = this->data;
        if (this->next!=NULL)
        {
            this->next = NULL;
            delete next;
        }
        cout<<"Memory is free for value "<<data<<endl;
    }
};

void InsertAtHead(Node *&head, Node *&tail, int d)
{
    //new node to insert at head
    Node *temp = new Node(d);

    //if linked list is NULL
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {

        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void InsertAtTail(Node *&head, Node *&tail, int d)
{
    //new node to insert at tail
    Node *temp = new Node(d);

    if (tail == NULL)
    {
        tail = temp;
        head = temp;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        temp->next = NULL;
        tail = temp;
    }
}

void InsertAtPosition(Node *&head, Node *&tail, int position, int d)
{

    Node *temp = head;
    for (int i = 1; i < position; i++)
    {

        temp = temp->next;
    }
    //insert at start
    if (position == 1)
    {
        InsertAtHead(head, tail, d);
        return;
    }
    //for last position insertion
    if (temp == NULL)
    {
        InsertAtTail(head, tail, d);
        return;
    }
    else //Baaki insertion ye sambhal lega
    {

        //new node to insert at middle
        Node *newNodeToInsert = new Node(d);
        newNodeToInsert->next = temp;
        temp->prev->next = newNodeToInsert;
        temp->prev = newNodeToInsert;
        newNodeToInsert->prev = temp->prev;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(Node* &head,Node* &tail,int position){

    //deleting first node
    if(position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = head->next;
        temp->next = NULL;
        delete temp; 
    }
    else{

        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        for (int i = 1; i < position; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        if(curr==tail)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

    }
}

int main()
{
    Node *node1 = NULL;
    Node *head = node1;
    Node *tail = node1;
    // print(head);
    InsertAtHead(head, tail, 5);
    print(head);
    InsertAtHead(head, tail, 2);
    print(head);
    InsertAtHead(head, tail, 1);
    print(head);
    InsertAtTail(head, tail, 4);
    print(head);
    InsertAtPosition(head, tail, 5, 7);
    print(head);
    InsertAtTail(head, tail, 0);
    print(head);
    deleteNode(head,tail,6);
    print(head);
    InsertAtTail(head, tail, 12);
    print(head);
    return 0;
}