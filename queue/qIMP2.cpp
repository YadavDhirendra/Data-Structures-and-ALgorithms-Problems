//Queue Implementation by Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class Queue{

    public:
    
    Node* front;
    Node* rear;

    Queue()
    {
       front = rear = NULL;
    }

    void enqueue(int x)
    {   
        //create a new node to insert
        Node* newNode = new Node(x);
        //if queue is empty then new node is front and rear both
        if(rear == NULL)
        {
            front = rear = newNode;
        }
        else{
            //add the new node at the end of the queue and change rear
            rear->next = newNode;
            rear = newNode;
        }

    }

    void dequeue()
    {
        //check if empty
        if(front == NULL)
        {
            cout<<"Queue is empty"<<endl;
            return ;
        }
        
        //Store previos front and move front one step ahead
        Node* temp = front;
        front = front->next;

        //if front becomes NULL, then change rear also as NULL 
        if(front==NULL)//single element pop
        rear = NULL;

        delete(temp);

    }

    int Front()
    {
        //check if empty
        if(front == NULL)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else
        return front->data;
    }
};

int main()
{
    
    return 0;
}