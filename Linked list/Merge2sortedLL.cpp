//Merge two sorted LL
#include<bits/stdc++.h>
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

void solve(Node* &first,Node* &second)
{   
    //dealing with 1 Node containing first LL
    if(first->next=NULL)
    {
        first->next = second;
        return ;
    }

    Node* curr1 = first;
    Node* curr2 = second;
    Node* next1 = curr1->next;
    Node* next2 = curr2->next;

    while (next1!=NULL && curr2!=NULL)
    {   

        //inserting curr2 Node in between first LL
        if((curr2->data>=curr1->data) && (curr2->data<=next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            //curr wale aage badhao
            curr1 = curr2;
            curr2 = next2;

        }
        else//first ke pointers aage badhao
        {
            curr1 = next1;
            next1 = next1->next;
            if(next1 == NULL)
            {
                curr1->next = curr2;
                // return first;
            }
        }
    }
//    return first; 
}

Node* MergeLL(Node* first,Node* second)
{   

    if(first == NULL)
    return second;

    if(second == NULL)
    return first;

    if(first->data<=second->data){
    solve(first,second);
    return first;
    }
    else if(first->data>=second->data){
     solve(second,first);
    return second;
    }

}

int main()
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* tail1 = node1;
    Node* tail2 = node2;
    Node* head1 = node1;
    Node* head2 = node2;
    InsertAtTail(tail1,4);
    InsertAtTail(tail1,5);
    InsertAtTail(tail2,3);
    InsertAtTail(tail2,5);
    print(head1);
    print(head2);
    Node* mergehead = MergeLL(head1,head2);
    print(mergehead);
    return 0;
}