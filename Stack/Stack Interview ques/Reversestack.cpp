//Reverse stack using recursion
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

void reverseStack(stack<int>& s)
{
    //base case
    if(s.empty())
    return ;

    int num =s.top();
    s.pop();

    //Baaki ye sab dekh lega
    reverseStack(s);

    //1 kadam badhaya
    InsertAtBottom(s,num);
}

int main()
{
     stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    reverseStack(s);
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
    
    return 0;
}