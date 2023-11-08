//Reverse a string using stack
//Key note : Stack stores data in reverse itself
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "Yadav";

    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }
    
    string ans = "";

    while (!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }

    cout<<"Reversed string is : "<<ans<<endl;
    

    return 0;
}