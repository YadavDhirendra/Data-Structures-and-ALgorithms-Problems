//Merge K sorted lists
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
        if (next != NULL)
            delete next;
    }
};

void InsertAtTail(Node* &tail,int d)
{
    Node* newNode = new Node(d);
    if(tail == NULL)
    {
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
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

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *mergeKLists(vector<Node *> &listArray)
{
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    int k = listArray.size();

    if (k == 0)
        return NULL;

    //step 1.
    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }

    Node *head = NULL;
    Node *tail = NULL;

    while (minHeap.size() > 0)
    {
        Node *temp = minHeap.top();
        minHeap.pop();
        if (temp->next != NULL)
        {
            minHeap.push(temp->next);
        }

        if (head == NULL)
        { //answer LL is empty
            head = temp;
            tail = temp;
        }
        else
        { //insert at Linked List
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

int main()
{
    Node* head1 = new Node(1);
    Node* head2 = new Node(11);
    Node* head3 = new Node(21);
    Node* tail1 = head1;
    Node* tail2 = head2;
    Node* tail3 = head3;

    InsertAtTail(tail1,2);
    InsertAtTail(tail1,3);
    InsertAtTail(tail1,4);
    
    InsertAtTail(tail1,12);
    InsertAtTail(tail1,13);
    InsertAtTail(tail1,14);

    InsertAtTail(tail1,22);
    InsertAtTail(tail1,23);
    InsertAtTail(tail1,24);

    vector<Node*> list = {head1,head2,head3};
    Node* head = mergeKLists(list);
    print(head);

    return 0;
}