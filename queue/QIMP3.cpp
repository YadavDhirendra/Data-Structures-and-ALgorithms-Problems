//Queue Implementation by using stacks
#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    stack<int> s1, s2;

    void enqueue(int x)
    {
        //Move all elements from s1 to s2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        //Push item into s1
        s1.push(x);

        //Push everything back to s1
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    //Dequeue an item from the queue
    int dequeue()
    {
        //if first stack is empty
        if (s1.empty())
        {
            cout << "Q is Empty" << endl;
            exit(0);
        }

        //Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}