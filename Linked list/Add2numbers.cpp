//Add two numbers represented by LL
#include<bits-stdc++.h>
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

void InsertAtTail(Node *&tail,int d){

    //new node to insert
    Node* newNode = new Node(d);

    //empty list
    if(tail== NULL)
    {
        tail = newNode;
        return;
    }
    else{

        tail->next = newNode;
        tail = newNode;
    }
}

void InsertAtHead(Node *&head,int d){

    //new node to insert
    Node* newNode = new Node(d);

    //empty list
    if(head== NULL)
    {
        head = newNode;
        return;
    }
    else{

       newNode->next = head;
       head = newNode;
    }
}

void print(Node* temp)
{
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* revLL(Node* head){

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next ;

    while (curr!=NULL)
    {
        forward  = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    
    return prev;
}

Node* addLL(Node* first,Node* second)
{
    //step 1.Reverse both LL
    first = revLL(first);
    second = revLL(second);

    //step 2.add 2 lL
    int carry = 0;
    Node* ans = NULL;
    while (first!=NULL || second!=NULL )
    {
        int val1 = 0;
        if(first!=NULL)
        val1 = first->data;
     
     
        int val2 = 0;
        if(second!=NULL)
        val2 = second->data;

        int sum = val1 + val2 + carry;
        int digit = sum%10;

        InsertAtHead(ans,digit);

        carry = sum/10;

        if(first != NULL)
        first = first->next;

        if(second!=NULL)
        second = second->next;
    }

    

    return ans;
}

int main()
{   
    //node 1 representing  no.45
    Node* node1 = new Node(4);
    Node* tail1 = node1;
    Node* head1 = node1;
    InsertAtTail(tail1,5);
    print(head1);
    //Node 2 representing no.345
    Node* node2 = new Node(3);
    Node* tail2 = node2;
    Node* head2 = node2;
    InsertAtTail(tail2,4);
    InsertAtTail(tail2,5);
    print(head2);
    Node* anshead = addLL(head1,head2);
    print(anshead);
    return 0;
}