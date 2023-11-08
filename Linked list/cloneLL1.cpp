//clone a linked list with next and a random pointer by approach 1
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    Node(int data){
        this->data = data;
        next = NULL;
        random = NULL;  
    }
};

void InsertAtTail(Node* &tail,Node* &head,int d){

    //new node to insert
    Node* newNode = new Node(d);

    //empty list
    if(tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void print1(Node* temp)
{
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void print2(Node* temp){

    while (temp!=NULL)
    {   
        if(temp->random!=NULL)
        cout<<temp->data<<"->"<<temp->random->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* cloneList(Node* head){

    //step 1.Create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* temp = head;

    while (temp!=NULL)
    {
        InsertAtTail(cloneTail,cloneHead,temp->data);
        temp = temp->next;  
    }
    
    //step 2.create a map
    unordered_map<Node*,Node*> OldtoNew;
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while (originalNode!=NULL)
    {
        OldtoNew[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    
    originalNode = head;
    cloneNode = cloneHead;

    while (originalNode!=NULL)
    {
        cloneNode->random = OldtoNew[originalNode->random];
        cloneNode = cloneNode->next;
        originalNode = originalNode->next;
    }
    
    return cloneHead;
}

int main()
{
    Node* node1 = new Node(1);
    Node* tail = node1;
    Node* head = node1;
    InsertAtTail(tail,head,2);
    InsertAtTail(tail,head,3);
    InsertAtTail(tail,head,4);
    InsertAtTail(tail,head,5);
    print1(head);
    //Declaring random pointers 1->2,2->5
    head->random = head->next;
    head->next->random = tail;
    print2(head);
    Node* cloneHead = cloneList(head);
    print1(cloneHead);
    print2(cloneHead);

    return 0;
}
