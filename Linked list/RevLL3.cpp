//Reverse Linked list by Approach 3
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


    //empty List
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

Node* RevLL3(Node* head)
{
    //base case
    if(head == NULL || head->next == NULL)
    return head;

    Node* chotaHead = RevLL3(head->next);

    head ->next->next = head;
    head->next = NULL;

    return chotaHead;
}

int main()
{
    Node* node1 = new Node(3);
    Node* head = node1;
    InsertAtHead(head,5);
    InsertAtHead(head,7);
    InsertAtHead(head,9);
    InsertAtHead(head,11);
    InsertAtHead(head,13);
    print(head);
    Node* revhead = RevLL3(head);
    print(revhead);
    return 0;
}