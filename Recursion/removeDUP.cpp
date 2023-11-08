//remove all adjacent duplicates in string
#include<bits/stdc++.h>
using namespace std;

string removeduplicates(string s)
{
    for (int i = 0; i < s.length(); i++)
    {   int k=0;
        for (int j = 1; j <s.length() ;)
        {
           if (s[j++]==s[k++])
           {
               s.erase(k-1,2);
               
           }
            
        }
        
    }
    return s;
}

int main()
{
    string s="azxxzy";
    string temp = removeduplicates(s);
    cout<<temp;
    return 0;
}