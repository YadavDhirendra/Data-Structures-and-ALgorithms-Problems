//Remove Duplicates in sorted LL
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }

    ~Node(){
        if(this->next!=NULL)
        {
            this->next = NULL;
            delete this;
        }
    }
};

void InsertAtHead(Node *&head, int d)
{

    //new node to insert
    Node *newNode = new Node(d);

    //empty list
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* uniqueSortedList(Node* head)
{
    //empty list
    if(head == NULL)
    return NULL;

    //non-empty list
    Node* curr = head;

    while (curr!=NULL)
    {
        if((curr->next!=NULL) && curr->data == curr->next->data)
        {
            Node* nextNode = curr->next->next;
            Node* node_to_delete = curr->next;
            delete node_to_delete;
            curr->next = nextNode;
           curr = curr->next;

        }
        else//not equal
        {
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    Node *node1 = new Node(3);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 2);
    InsertAtHead(head, 2);
    InsertAtHead(head, 1);
    InsertAtHead(head, 1);
    print(head);
    Node* uniquehead = uniqueSortedList(head);
    print(uniquehead);
    return 0;
}