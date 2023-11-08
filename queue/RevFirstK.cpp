//Reverse first K elements of queue
#include<bits/stdc++.h>
using namespace std;

queue<int> revK(queue<int> q, int k)
{   
    stack<int> s;
    int n = q.size();
    //step 1.pop first K elements from queue & insert these into stack
    for (int i = 0; i < k; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    //step 2.Insert back from stack to queue
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    //Now place first (n-k) elements from front to rear
    for (int i = 0; i < n-k; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
    
    
}

int main()
{
    queue<int> q ;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k = 3;
    queue<int> revQ = revK(q,k);
    cout<<revQ.front()<<endl;
    revQ.pop();
    cout<<revQ.front()<<endl;
    revQ.pop();
    cout<<revQ.front()<<endl;
    revQ.pop();
    cout<<revQ.front()<<endl;
    revQ.pop();
    cout<<revQ.front()<<endl;
    return 0;
}