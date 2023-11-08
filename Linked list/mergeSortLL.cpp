//Merge sort in Linked List
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

void InsertAtTail(Node* &tail,int d)
{
    //new Node to insert
    Node* newNode = new Node(d);

    //empty list
    if(tail==NULL)
    {
        tail = newNode;
    }
    else{
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

Node* getMid(Node* head){

    Node* slow = head;
    Node* fast = head->next;

    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* first,Node* second)
{
    if(second == NULL)
    return first;

    if(first == NULL)
    return second;

    Node* ans = new Node(-1);
    Node* temp = ans;
    while (first!=NULL && second!=NULL)
    {
        if(first->data>second->data)
        {
            temp->next  = second;
            temp = second;
            second = second->next;
        }
        else{
            temp->next = first;
            temp = first;
            first = first->next;
        }
        
    }

    while (first!=NULL)
    {
        temp ->next = first;
        temp = first;
        first = first->next;
    }

    while (second!=NULL)
    {
        temp->next = second;
        temp = second;
        second = second->next;
    }
    ans = ans->next;
    return ans;    
}

Node* mergeSortLL(Node* head)
{
    //base case
    if(head==NULL || head->next==NULL)
    return head;

    //break linked list into 2 halves
    Node* mid = getMid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    //recursive calls for sorting
    left = mergeSortLL(left);
    right = mergeSortLL(right);

    //merge left and right sorted lists
   Node* result = merge(left,right);

   //return ans
   return result;

}

int main()
{
    Node* node1 = new Node(10);
    Node* tail = node1;
    Node* head = node1;
    InsertAtTail(tail,2);
    InsertAtTail(tail,1);
    InsertAtTail(tail,19);
    InsertAtTail(tail,0);
    InsertAtTail(tail,5);
    print(head);
    Node* sortedhead = mergeSortLL(head);
    print(sortedhead);
    return 0;
}