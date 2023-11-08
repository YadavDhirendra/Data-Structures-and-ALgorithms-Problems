//The celebrity problem*
//conditions : 1.Everybody knows celebrity
// 2.Celebrity knows noone
#include <bits/stdc++.h>
using namespace std;

bool knows(int a, int b, int M[][100])
{
    if (M[a][b] == 1)
        return 1;
    else
        return 0;
}

int celebrity(int M[][100], int n)
{
    stack<int> s ;
    //step 1.Push all elements in stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    //step 2.Compare all elements in stack to know about who is celebrity

    while (s.size() != 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(a, b, M))
            s.push(b);
        else
            s.push(a);
    }

    //step 3.now single element in stack is celebrity
    //verifying by checking all rows and cols

    int candidate = s.top(); //candidate who claims for being celeb
    int zerocount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[candidate][i] == 0)
            zerocount++;
    }
    //zero count
    if (zerocount != n)
        return -1;

    int onecount = 0;
    for (int i = 0; i < n; i++)
    {
        if (M[i][candidate] == 1)
            onecount++;
    }
    //one count
    if (onecount != n - 1)
        return -1;

    return candidate;
}

int main()
{
    int M[][100] = {{0, 1, 0},
                    { 0,0,0,},
                    {0, 1, 0}};
    int n = 3;
    cout<<"The celebrity of given matrix is : "<<celebrity(M,n);
    return 0;
}