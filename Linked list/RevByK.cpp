//Reverse the Linked List by 'k' groups
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

Node* RevByK(Node* head,int k)
{
    //base call
    if(head == NULL)
    return NULL;

    //step1.reverse first 'k' nodes
    int cnt = 0;
    Node* forward = NULL;
    Node* curr = head;
    Node* prev = NULL;

    while (cnt<k && curr!=NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        cnt++;
    }
    
    //Step2. Baaki recursion dekhlega
    if(forward!=NULL)
    {
        head->next = RevByK(forward,k);
    }

    //step 3. return head of reversed list
    return prev;
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
    int k=3;
    Node* revhead  = RevByK(head,k);
    print(revhead);
    return 0;
}