//Queue reversal by using stack
#include<bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q)
{   
    stack<int> s;

    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        s.push(val);    
    }
    
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    return q;
}

int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);
    queue<int> revQ = rev(q);
    cout<<"Queue front : "<<q.front()<<" Reversed queue front : "<<revQ.front()<<endl;
    return 0;
}