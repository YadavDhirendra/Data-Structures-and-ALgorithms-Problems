//Circular Queue Implantation
#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty()
    {
        if(front == -1)
        return 1;
        else
        return 0;
    }

    bool enqueue(int value)
    {
        //check if full
        if ((front == 0 && rear == size-1) || (rear == (front-1) % (size-1)))
        {
            cout << "Queue is full";
            return false;
        }
        else if (front == -1) //first element to push
        {
            front = rear = 0;
        }
        else if (front != 0 && rear == size - 1) //to maintain cyclic order
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    int dequeue()
    {
        //check if empty
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) //single element present
        {
            front = rear = -1;
        }
        else if (front == size - 1) //to maintain cycle order
        {
            front = 0;
        }
        else
        {
            front ++;
        }
        return ans;
    }

    int Qfront()
    {
        //check if empty
        if(isEmpty())
        {
            cout<<"Queue is full"<<endl;
            return -1;
        }
        else
        return arr[front];
    }
};

int main()
{
    CircularQueue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    // cout<<q.Qfront<<endl;
    cout<<"Front is : "<<q.arr[q.front]<<"  Rear is : "<<q.arr[q.rear]<<endl;
    q.dequeue();
    cout<<"Front is : "<<q.arr[q.front]<<"  Rear is : "<<q.arr[q.rear]<<endl;
    // cout<<q.Qfront<<endl;
    // cout<<q.arr[q.front]<<endl;
    return 0;
}