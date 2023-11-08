//K queues in an array of sized n
#include<bits/stdc++.h>
using namespace std;

class kQueue{
    public:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;
    int n;
    int k;

    kQueue(int n,int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        //Initializing front and rear with -1
        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;    
        }
        
        //Initializing next with next empty indeices and last with -1
        for (int i = 0; i < n; i++)
        {
            next[i] = i+1;
        }
        
        next[n-1] = -1;
        freespot = 0;

    }

    void enqueue(int data,int qn)
    {
        //check if overflow
        if(freespot == -1)//when it get to (n-1) index
        {
            cout<<"No empty space is present"<<endl;
            return;
        }

        //find first free index
        int index = freespot;
        
        //update freespot
        freespot = next[index];

        //check whether first element
        if(front[qn-1] == -1)
        {   
            front[qn-1] = index;
        }
        else
        {   //link new element to prev one
            next[rear[qn-1]] = index;   //rear[qn-1] stands for the place(index) where previous value has stored
        }

        //update next
        next[index] = -1;

        //update rear
        rear[qn-1] = index;
        
        //insert data in above index of array 
        arr[index] = data;
    }

    int dequeue(int qn)
    {
        //check if underflow
        if(front[qn-1] == -1)
        {
            cout<<"Queue is underflow"<<endl;
            return -1;
        }

        //find index to pop
        int index = front[qn-1];

        //front ko aage badhao
        front[qn-1] = next[index];

        //freeslots ko manage karo
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }

    int Front(int qn)
    {
        //check if underflow
        if(front[qn-1] == -1)
        {
            cout<<"Queue is underflow"<<endl;
            return -1;
        }

        return arr[front[qn-1]];
    }
};

int main()
{
    kQueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    cout<<q.Front(1)<<endl;
    q.dequeue(1);
    cout<<q.Front(1)<<endl;
    cout<<q.Front(2)<<endl;
    cout<<q.Front(3)<<endl;
    return 0;
}