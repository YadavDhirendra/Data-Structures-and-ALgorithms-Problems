//Design a stack that supoorts getMin() in O(1) time and O(1) extra space
#include <bits/stdc++.h>
using namespace std;

class specialstack
{
    //Data members needed
    stack<int> s;
    int mini;

public:
    void push(int data)
    {
        if (s.empty())
        {
            s.push(data);
            mini = data;
        }
        else
        {
            if (data > s.top())
            {
                s.push(data);
            }
            else
            {
                //here data is now new min and mini is treated as prevmin
                int val = 2 * data - mini;
                s.push(val);
                mini = data;
                //with the help of val we can retrieve previous min
            }
        }
    }

    int pop()
    {
        //check if empty
        if (s.empty())
            return -1;

        int val = s.top();
        s.pop();
        if (val > mini)
            return val;
        else
        {   
            int prevmin = mini;
            mini = 2*prevmin - val;
            return prevmin;
        }
    }

    int top()
    {
        if(s.empty())
        return -1

        int curr = s.top();

        if(curr > mini)
        return curr;

    
    }
};

int main()
{

    return 0;
}