//Sort 0s ,1s and 2s in LL by approach 2(changing next)
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

void InsertAtTail(Node* &tail,int d){

    //new node to insert
    Node* newNode = new Node(d);

    //empty list
    if(tail == NULL)
    {
        tail = newNode;
        return; 
    }
    else{
        //non-empty list
        tail->next = newNode;
        tail = newNode;
    }
}

void InsertAtTail2(Node* &tail,Node* &curr){

    tail->next = curr;
    tail = curr;
   
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

Node* SortList(Node* head){

    Node* zerohead = new Node(-1);
    Node* onehead = new Node(-1);
    Node* twohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onetail = onehead;
    Node* twotail = twohead;

    Node* temp =head;
    
    while (temp!=NULL)
    {
        if(temp->data == 0)
        {
            InsertAtTail2(zerotail,temp);
        }
        else if(temp->data == 1)
        {
            InsertAtTail2(onetail,temp);
        }
        else if(temp->data == 2)
        {
            InsertAtTail2(twotail,temp);
        }
        temp = temp->next;
    }
    

    if(onehead->next!=NULL)
    {
        zerotail->next = onehead->next;
        onetail->next = twohead->next;
    }
    else{
        zerotail->next = twohead->next;
    }

    twotail->next =NULL;
    
    head = zerohead->next;
    zerohead->next = NULL;
    onehead->next = NULL;
    twohead->next = NULL;
    delete zerohead;
    delete onehead;
    delete twohead;

   return head; 
    
}

int main()
{
    Node* node1 = new Node(1);
    Node* tail = node1;
    Node* head = node1;
    InsertAtTail(tail,0);
    InsertAtTail(tail,2);
    InsertAtTail(tail,1);
    InsertAtTail(tail,2);
    print(head);
    Node* sorthead = SortList(head);
    print(sorthead);
    return 0;
}