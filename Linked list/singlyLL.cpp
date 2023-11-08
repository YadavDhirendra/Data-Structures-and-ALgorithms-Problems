//SIngly Linked list Implementation code
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {   
            this->next = NULL;
            delete next;
        }
        cout << "Memory is free for value " << value << endl;
       
    }
};

void InsertAtHead(Node *&head, int d)
{

    //new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
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

void InsertAtTail(Node *&tail, int d)
{
    //new node create
    Node *temp = new Node(d);

    tail->next = temp;
    tail = temp;
}

void InsertAtPosition(Node *&head, int position, int d)
{
    //insert at start
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }

    //creating a node to insert
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head)
{
    //deletion of first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else//deletion for middle element or last one
    {
        Node *curr = head;
        Node *prev = NULL;

        for (int i = 1; i < position; i++)
        {
            prev = curr;
            curr = curr->next;
        }

      prev->next = curr->next;
      curr->next= NULL;
      delete curr;
    }
}

void deletebyvalue(Node* &head,int value){

    //deleting node at start
    if(head->data == value)
    {
        Node* temp = head;
        head = head->next;
        temp ->next = NULL;
        delete temp;
    }

    else{//deleting node at middle
    Node *curr = head;
    Node *prev = NULL;

    while (curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    }

}

int main()
{
    //creating a node
    Node *node1 = new Node(10);

    //head and tail pointed to node1
    Node *head = node1;
    Node *tail = node1;

    InsertAtTail(tail, 5);
    print(head);
    InsertAtTail(tail, 7);
    print(head);
    InsertAtTail(tail, 9);
    print(head);
    InsertAtPosition(head, 5, 1);
    print(head);
    deleteNode(1,head);
    print(head);
    InsertAtHead(head,4);
    print(head);
    deletebyvalue(head,4);
    print(head);
    return 0;
}