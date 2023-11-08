//Detect loop in LL by Map
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

bool detectLoop1(Node *head)
{
    if (head == NULL)
        return 0;

    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        //if cycle is present
        if (visited[temp] == 1)
            return 1;

        visited[temp] = 1;
        temp = temp->next;
    }

    return 0;
}

bool detectLoop2(Node *head) //Floyd cycle algorithm
{
    //empty list
    if (head == NULL)
        return 0;

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {

        slow = slow->next;
        fast = fast->next;

        if (fast->next != NULL)
            fast = fast->next;
        //if cycle is present
        if (fast == slow)
            return 1;
    }

    return 0;
}

Node *StartingNodeofCycle(Node *head)
{
    /*Algorith : Step 1. perform Floyd cycle detection algo and find POI of slow and fast
                step 2. Now reinitialize slow to head 
                step 3. Where slow and fast meet now shall be our starting node of cycle
    */
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {

        slow = slow->next;
        fast = fast->next;

        if (fast->next != NULL)
            fast = fast->next;

        //finding point of inter. of slow and fast in cycle
        if (fast == slow){
            break;
        }
    }
    slow = head;
    while (slow!=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
    
}

void Removeloop(Node* head)
{
    Node* start = StartingNodeofCycle(head);
    Node* curr = start;

    while (curr->next!=start)
    {
        curr = curr->next;
    }
    
    curr->next = NULL;
    
    
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    InsertAtHead(head, 3);
    InsertAtHead(head, 2);
    InsertAtHead(head, 6);
    InsertAtHead(head, 5);
    tail->next = head->next; //cycle prepared
    // print(head);
    if (detectLoop2(head))
        cout << "Cycle is present.." << endl;
    else
        cout << "Sorry! no cycle is present" << endl;

    cout<<"The starting Node of cycle is "<<StartingNodeofCycle(head)->data<<endl;
    Removeloop(head);
    print(head);
    return 0;
}