//removing all occurances of substring
#include<bits/stdc++.h>
using namespace std;

string removeoccurences(string s, string part)
{
    while (s.length()!=0 && s.find(part)<s.length())
    {
        s.erase(s.find(part),part.length());
    }
    return s;
}

int main()
{
    string s="daabcbaabcbc",part="abc";
    string temp = removeoccurences(s,part);
    cout<<temp;
    return 0;
}