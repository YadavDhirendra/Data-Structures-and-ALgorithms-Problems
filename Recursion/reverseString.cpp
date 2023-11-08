//Reverse string by recusion
#include <bits/stdc++.h>
using namespace std;

void revstring(string &str, int i, int j)
{
    //base case
    if (i > j)
        return;
    else
    {
        swap(str[i++],str[j--]);
        revstring(str,i,j);
    }
}

int main()
{
    string s = "Yadav";
    int i = 0, j = s.length() - 1;
    revstring(s,i,j);
    cout<<s;
    return 0;
}