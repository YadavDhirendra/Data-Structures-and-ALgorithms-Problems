//Dequeue Implementation
//operations : 1.push_front
//2.push_back
//3.pop_front
//4.pop_back
#include <bits/stdc++.h>
using namespace std;

class Deque
{

public:
    int *arr;
    int front;
    int rear;
    int size;

    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    bool isEmpty()
    {
        if(front==-1)
        return 1;
        else
        return  0;
    }

    bool pushfront(int x)
    {
        //check if full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else if (front == -1) //Queue is empty
        {
            front = rear = 0;
        }
        else if (front == 0) //As if we pop then front inc. so for push it must be dec.
        {
            front = size - 1; //to maintain cycle order
        }
        else
        {
            front--;
        }
        arr[front] = x;
    }

    bool pushrear(int x)
    {
        //check if full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            cout << "Queue is full" << endl;
            return false;
        }
        else if (front == -1) //Queue is empty
        {
            front = rear = 0;
        }
        else if (rear == size-1 && front!=0)
        {
            rear = 0; //to maintain cycle order
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
    }

    int poprear()
    {
        //check if empty
        if(front == -1)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(front == rear)//single element
        {
            front = rear = -1;
        }
        else if(rear == 0)//to maintain cycle order
        {
            rear = size-1;
        }
        else{//normal pop
            rear--;
        }
        return ans;
    }
    int popfront()
    {
        //check if empty
        if(front == -1)
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear)//single element
        {
            front = rear = -1;
        }
        else if(front == size -1)//to maintain cycle order
        {
           front = 0;
        }
        else{//normal pop
            front++;
        }
        return ans;
    }

    int Front()
    {
        //check if empty
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    int Rear()
    {
        //check if empty
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[rear];
    }
};

int main()
{
    Deque q(10);
    q.pushfront(1);
    q.pushfront(0);
    q.pushrear(3);
    q.pushrear(4);
    cout<<"Front is : "<<q.Front()<<" Rear is : "<<q.Rear()<<endl;
    q.popfront();
    cout<<"Front is : "<<q.Front()<<" Rear is : "<<q.Rear()<<endl;
    q.poprear();
    cout<<"Front is : "<<q.Front()<<" Rear is : "<<q.Rear()<<endl;

    return 0;
}