//Design a data tructure to implement 'N' stacks in a single array of size 'S'.It should support the following operations
//Approach : For PUSH :Lets's take an example of 9-sized array in which 3-stacks to insert
//so there will be two extra arrays 
//1. top[] -> represent index of top elements no . of top = no. of stack
//2. next[] -> a) points to next element after stack top(previos top of corr. stack) or
//b) points to next free space and size of next = size of array
//For POP : just go in reverse order 
#include<bits/stdc++.h>
using namespace std;

class NStack{
    int *arr;
    int *top;
    int *next;
    
    int freespot;
    int n,s;
    
    public:
    NStack(int N,int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        //Initializing all top to -1
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        
        //initializing next in which each element represents next free space except last points -1
        for (int i = 0; i < s; i++)
        {
            next[i] = i+1;
        }
        next[s-1] = -1;

        //Initializing first freespot
        freespot = 0;
    }
    
    //Pushing 'x' into the Mth stack,returns true if it gets pushed
    bool push(int x,int m)
    {
        //check for overflow
        if(freespot == -1){
            return false;
        }

        //find index
        int index = freespot;

        //update freespot
        freespot = next[index];

        //insert the value
        arr[index] = x;

        //udpate next
        next[index] = top[m-1];

        //update top
        top[m-1] = index;

        return true;

    }

    //Pops top element from Mth stack> Returns -1 if the stack is empty ,otherwise returns the popped value
    int pop(int m)
    {
        //check underflow condition
        if(top[m-1] == -1)
        return -1;

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];


    }
};

int main()
{
    NStack s(9,3);
    s.push(10,1);
    s.push(20,1);
    s.push(0,2);

     cout<< s.pop(1);
    return 0;
}