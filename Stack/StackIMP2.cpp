//Stack Implementation by using queue
#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    queue<int> q1,q2;

    void push(int x){

        //Move all elements from q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();   
        }
        
        //Push x into q1
        q1.push(x);

        //Push everything back from q2 to q1
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        
    }

    int pop()
    {
        //if first queue is empty
        if(q1.empty())
        {
            cout<<"Stack is empty"<<endl;
            exit(0);
        }

        //Return front of q1
        int x = q1.front();
        q1.pop();
        return x;
    }
};

int main()
{
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    return 0;
}