//Remove Duplicates in unsorted LL
#include <bits/stdc++.h>
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

    ~Node()
    {
        if (this->next != NULL)
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

Node *removeDup(Node *head)
{
    Node *curr = head;

    while (curr != NULL)
    {
        Node *temp = curr->next;

        while (temp != NULL)
        {
            if ((temp->next!=NULL) &&curr->data == temp->next->data)
            {
                Node *nextNode = temp->next->next;
                Node *node_to_delete = temp->next;
                temp->next = nextNode;
                delete node_to_delete;
            }
            else
            {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
    return head;
}

int main()
{
    Node *node1 = new Node(-1);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 2);
    InsertAtHead(head, 2);
    InsertAtHead(head, 4);
    InsertAtHead(head, 5);
    InsertAtHead(head, 2);
    InsertAtHead(head, 4);
    print(head);
    Node *remduphead = removeDup(head);
    print(remduphead);
    return 0;
}