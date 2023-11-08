//Redundant Brackets
#include <bits/stdc++.h>
using namespace std;

bool redundantBra(string str)
{
    stack<int> s;
            bool redundant = true;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        //if ch contains opening brackets or operators then push into stack
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            s.push(ch);

        //ch contais lowercase letter or closing brackets
        else
        {

           if(ch == ')'){
               redundant = true;
               while (s.top()!='(')
               {
                   char top = s.top();
                   if(top == '+' || top == '-' || top == '*' || top == '/')
                   redundant = false;
                   s.pop();
               }

               if(redundant)
               return true;
               s.pop();
           }
        }
    }
   return false;
}

int main()
{
    string str = "((a*b))";
    if(redundantBra(str))
    cout<<"Given string has redundant brackets "<<endl;
    else
    cout<<"Given string has no redundant brackets"<<endl;
    return 0;
}