//Interleave the first half of the queue with second half
//constraints : Only stacks can be used as an auxilliary space
#include<bits/stdc++.h>
using namespace std;

queue<int> InterleaveHalfWithSecond(queue<int> q)
{   
    int n = q.size();
    // cout<<n<<endl;
    stack<int> s;
    //step 1.Fetch first half elements into stack from queue
    for (int i = 0; i < n/2; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    //step 2.Fetch previous elements from stack to queue
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    
    //step 3.Now Place first half elements from front to rear
    for (int i = 0; i < n/2; i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
    
    //step 4.Repeat step 1
    for (int i = 0; i < n/2; i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    //step 5.Last step Mix step 2 and 3
    while (!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
        
        val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    queue<int> iq = InterleaveHalfWithSecond(q);
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<q.front()<<" ";
    q.pop();
    cout<<endl;
    cout<<iq.front()<<" ";
    iq.pop();
    cout<<iq.front()<<" ";
    iq.pop();
    cout<<iq.front()<<" ";
    iq.pop();
    cout<<iq.front()<<" ";
    iq.pop();
    cout<<iq.front()<<" ";
    iq.pop();
    cout<<iq.front()<<" ";
    iq.pop();
    cout<<iq.front()<<" ";
    iq.pop();
    cout<<iq.front()<<" ";
    iq.pop();
    cout<<iq.front()<<" ";
    iq.pop();
    cout<<iq.front()<<" ";
    iq.pop();
    cout<<endl;
    return 0;
}