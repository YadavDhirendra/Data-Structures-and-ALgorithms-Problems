//Queue implementation by array
#include<bits/stdc++.h>
using namespace std;

class Queue{

    int *arr;
    int front;
    int rear;
    int size;
    public:
    Queue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = 0;

    }

    bool isEmpty()
    {   
        if(front == rear)
        return 1;
        else
        return 0;
       
    }

    void enqueue(int data)
    {
        //check if full
        if(rear == size)
        {
            cout<<"queue is full"<<endl;
        
        }
        else{
            arr[rear++] = data; 
        }
    }

    int dequeue()
    {
        //check if empty
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            int ans = arr[front];
            arr[front++] = -1;
            if(front==rear)
            front = rear = 0;
            return ans;
        }
    }

    int Qfront()
    {
        //check if empty
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else
        return arr[front];
    }
};

int main()
{
    Queue q(10);
    q.enqueue(1);
    q.enqueue(2);
    cout<<q.Qfront()<<endl;
    q.dequeue();
    cout<<q.Qfront()<<endl;
    return 0;
}