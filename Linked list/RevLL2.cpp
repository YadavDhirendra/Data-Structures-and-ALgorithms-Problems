//Reverse Linked List by Approach 2(Recursive sol)
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
    Node* newNode = new Node(d);

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

void print(Node* head)
{
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* RevLL2(Node* forward,Node* prev ,Node* curr)
{

    //base case
    if(curr == NULL)
    return prev;

    //recursive calls
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    RevLL2(forward,prev,curr);

}

int main()
{
    Node* node1 = new Node(3);
    Node* head = node1;
    InsertAtHead(head,5);
    InsertAtHead(head,7);
    InsertAtHead(head,9);
    print(head);
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;
    Node* revhead = RevLL2(forward,prev,curr);
    print(revhead);
    return 0;
}