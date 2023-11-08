//Insert an Element in bottom of stack
#include<bits/stdc++.h>
using namespace std;

void InsertAtBottom(stack<int>&s,int data){

    //base case
    if(s.empty()){
        s.push(data);
        return;
    }

    int num = s.top();
    s.pop();

    //Recursive calls
    InsertAtBottom(s,data);

    s.push(num);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    InsertAtBottom(s,0);
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
     n = s.top();
    cout<<n<<" ";
    s.pop();
     n = s.top();
    cout<<n<<" ";
    s.pop();
    return 0;
}