//Reverse words in a string
//example : i/p = "the sky is blue"
//o/p = "eht yks si eulb"
#include <bits/stdc++.h>
using namespace std;

string revwords(string ch)
{
    char c = ' ';
    int i = 0, j = 0;
    string temp = "";
    while (ch[i] != '\0')
    {
        i++;
        //for space and null char location
        while (ch[i] != c || ch[i] != '\0')
            i++;

        for (int k = i - 1; k >= j; k--)
        {
            temp.push_back(ch[k]);
        }
        temp.push_back(c);

        j = i + 1;
    }
    temp.pop_back();
    return temp;
}

int main()
{
    string ch = "the sky is blue";
    string temp = revwords(ch);
    cout << temp;
    return 0;
}