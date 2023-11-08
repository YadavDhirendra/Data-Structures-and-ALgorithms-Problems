//Sorting stack
#include <bits/stdc++.h>
using namespace std;

void sortingInsert(stack<int> &s, int data)
{
    //base case
    if(s.empty() || s.top()<data){
    s.push(data);
    return;
    }

    int num = s.top();
    s.pop();
   

    //recursive calls
    sortingInsert(s,data);

    //backtracking
    s.push(num);

}

void sortStack(stack<int> &s)
{
    //base case
    if (s.empty())
        return;

    int num = s.top();
    s.pop();

    //Baaki ye sab dekh lega
    sortStack(s);

    //1 kadam badhao
    sortingInsert(s, num);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(2);
    s.push(5);
    s.push(-1);
    s.push(0);
    sortStack(s);
    int n = s.top();
    cout << n << " ";
    s.pop();
    n = s.top();
    cout << n << " ";
    s.pop();
    n = s.top();
    cout << n << " ";
    s.pop();
    n = s.top();
    cout << n << " ";
    s.pop();
    n = s.top();
    cout << n << " ";
    s.pop();

    return 0;
}