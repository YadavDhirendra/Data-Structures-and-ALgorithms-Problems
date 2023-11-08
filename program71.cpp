//Reverse words in a string
//example : i/p = "the sky is blue"
//o/p = "blue is sky the"
#include<bits/stdc++.h>
using namespace std;

string revwords(string ch)
{   
    //already reversed all chars
    reverse(ch.begin(),ch.end());

    ch.insert(ch.end(),' ');

    int n = ch.length();
    int j=0;

    for (int i = 0; i < n; i++)
    {
        if (ch[i]== ' ')
        {
            reverse(ch.begin()+j,ch.begin()+i);
        }
        
        j=i+1;
    }
 ch.pop_back();   
return ch;
}

int main()
{
    string ch = "the sky is blue";
    string temp =  revwords(ch);
    cout<<temp;
    return 0;
}