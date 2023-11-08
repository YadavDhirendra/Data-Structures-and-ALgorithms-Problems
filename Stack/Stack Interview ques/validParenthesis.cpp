//Valid Parenthesis using stack
#include <bits/stdc++.h>
using namespace std;

bool isvalidParentheis(string str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {

        char ch = str[i];

        //if opening bracket ,stack push
        //if close bracket , stacktop cheack and pop
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }

        else
        {
            //for cloasing brackets
            if(!s.empty()){
                char top = s.top();
                if((ch=='}' && top == '{') || (ch==']' && top == '[') || (ch==')' && top == '('))
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    //atlast if every opening braces have been cancelled by their corresponding closing braces then list will be empty
    if(!s.empty())
    return false;
    else
    return true;

}

int main()
{
    string str = "[]{}(){";
    if(isvalidParentheis(str))
    cout<<"Given string is valid"<<endl;
    else
    cout<<"sorry given string is not valid"<<endl;
    return 0;
}