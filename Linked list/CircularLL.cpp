//Circular Linked List (there's no start and end)
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
        next = this;
    }

    ~Node()
    {
        int value = data;
        if (this->next != NULL)
        {
            this->next = NULL;
            delete this;
        }
        cout << "Memory is free for value " << value << endl;
    }
};

void InsertNode(Node *&tail, int element, int d)
{
    //new Node to insert
    Node *newNode = new Node(d);

    //if Linked List is empty
    if (tail == NULL)
    {
        tail = newNode;
        newNode->next = newNode;
        return;
    }
    else
    {
        //non-empty List
        //assuming that the element is present in the list
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        //element found -> curr is representing element wala node
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void print(Node *tail)
{
    Node *temp = tail;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);

    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    //empty list
    if (tail == NULL)
    {
        cout << "Sorry But List is empty!" << endl;
        return;
    }
    else//rest of the deletion
    {
        Node *prev = tail;
        Node *curr = tail->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        //Now curr representing the node which would be deleted
        
        prev->next = curr->next;
        //deleting tail node and updating it
        if(curr == tail)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *node1 = new Node(10);
    Node *tail = node1;

    print(tail);
    InsertNode(tail, 10, 3);
    print(tail);
    InsertNode(tail, 3, 5);
    print(tail);
    InsertNode(tail, 5, 7);
    print(tail);
    InsertNode(tail, 10, 9);
    print(tail);
    
    deleteNode(tail, 10);
    print(tail);
    return 0;
}