//Delete middle element from stack
#include<bits/stdc++.h>
using namespace std;

void deleteMid(stack<int> &s,int mid,int count)
{
    //base case
    if(count == mid){
    s.pop();
    return;
    }

    //store top for backtracking
    int num = s.top();
    s.pop();

    //recursive calls
    deleteMid(s,mid,count+1);

    //backtracking for top elements that have popped before mid one
    s.push(num);
}

stack<int> display(stack<int> s)
{   
    stack<int> s1;
    stack<int> s2;
    while (!s.empty())
    {
        cout<<s.top();
        s1.push(s.top());
        s.pop();
        if(!s.empty())
        cout<<" -> ";

    }
    cout<<endl;
    while (!s1.empty())
    {
        
        s2.push(s1.top());
        s1.pop();
    }

   return s2;
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int mid = s.size()/2;
    deleteMid(s,mid,0);
    
    int n = s.top();
    cout<<n<<" ";
    s.pop();
     n = s.top();
    cout<<n<<" ";
    s.pop();
     n = s.top();
    cout<<n<<" ";
    s.pop();
     n = s.top();
    cout<<n<<" ";
    s.pop();
    
    return 0;
}