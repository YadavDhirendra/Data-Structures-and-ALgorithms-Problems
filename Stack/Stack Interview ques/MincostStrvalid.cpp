//minimum cost to make string valid
//keypoint : 1.odd no. of braces never make string valid
//2. cost = (a+1)/2 + (b+1)/2 where a -> no. of opening braces and b -> no. of closing braces
#include <bits/stdc++.h>
using namespace std;

int mincostTomakeStringvalid(string str)
{
    //odd condition
    if (str.length() % 2 != 0)
        return -1;

    //remove valid braces already from string and insert it into stack
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{')
            s.push(ch);
        else
        {
            //ch is closing braces
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
                s.push(ch);
        }
    }
    //now stack contains invalid braces
    int a = 0, b = 0;
    while (!s.empty())
    {
        char ch = s.top();
        if(ch == '{')
        a++;
        else if(ch == '}')
        b++;
        s.pop();

    }
    int ans = (a+1)/2 + (b+1)/2;
    return ans;
}

int main()
{
    string str = "{{}}}{";
    cout<<"Minimum cost to make string valid is "<<mincostTomakeStringvalid(str);
    return 0;
}