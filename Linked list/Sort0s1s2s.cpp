//Sort 0s ,1s and 2s in LL
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

    int zerocnt = 0;
    int twocnt = 0;
    int onecnt = 0;

    Node* temp = head;
    while (temp!=NULL)
    {
        if(temp->data == 0)
        zerocnt++;
        else if(temp->data == 1)
        onecnt++;
        else if(temp->data == 2)
        twocnt++;

        temp = temp->next;
    }

    temp = head;

    while (temp!=NULL)
    {
        if(zerocnt != 0)
        {
            temp->data = 0;
            zerocnt--;
        }
        else if(onecnt != 0)
        {
            temp->data = 1;
            onecnt--;
        }
        else if(twocnt != 0){
            temp->data = 2;
            twocnt--;
        }
        temp = temp->next;
    }

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