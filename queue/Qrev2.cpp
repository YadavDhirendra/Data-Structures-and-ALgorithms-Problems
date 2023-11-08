//Queue reversal by using recursion
#include<bits/stdc++.h>
using namespace std;

void rev(queue<int> &q,int count,int len)
{   
    //base case
    if(count == len-1)
    return ;

    int val = q.front();
    q.pop();

    //Recusive calls
    rev(q,count+1,len);

    q.push(val);
    

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
    cout<<"Queue front : "<<q.front()<<endl;
     rev(q,0,6);
    cout<<"REversed Queue front : "<<q.front()<<endl;
    q.pop();
    cout<<"REversed Queue front : "<<q.front()<<endl;

    return 0;
}