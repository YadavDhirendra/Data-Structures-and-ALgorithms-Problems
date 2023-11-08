//Is linked list circular or not
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = this;
    }
};

void InsertNode(Node *&tail, int element, int d)
{
    //new Node to insert
    Node *newNode = new Node(d);

    //if Linked List is empty
    if (tail == NULL)
    {
        tail = newNode;
        newNode->next = newNode;
        return;
    }
    else
    {
        //non-empty List
        //assuming that the element is present in the list
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        //element found -> curr is representing element wala node
        newNode->next = curr->next;
        curr->next = newNode;
    }
}


void print(Node* tail)
{   
    Node* temp = tail;
    do
    {   
        cout<<temp->data<<" ";
        temp = temp->next;
        
    } while (temp!=tail);
    cout<<endl;
    
}

bool Iscircular(Node* tail,Node* temp)
{   

    //base cases
    if(temp==NULL || temp->next==NULL)
    return 0;
    if(temp->next==tail)
    return 1;

    temp = temp->next;
    return Iscircular(tail,temp);
}

int main()
{
    Node* node1 = new Node(1);
    Node*tail = node1;
    print(tail);
    InsertNode(tail,1,3);
    print(tail);
    InsertNode(tail,3,4);
    print(tail);
    InsertNode(tail,1,5);
    print(tail);
    InsertNode(tail,4,6);
    print(tail);
    InsertNode(tail,5,7);
    print(tail);
    Node* temp = tail;
    if(Iscircular(tail,temp))
    cout<<"Given LL is circular"<<endl;
    else
    cout<<"Given Linked list is not circular"<<endl;
    return 0;
}