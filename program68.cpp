//check if given sstring is palindrome
#include <bits/stdc++.h>
using namespace std;
bool checkpal(string a)
{
    int s = 0, e = a.length() ;
    int temp = 0;
    while (s <= e)
    {
        if (a[s++] == a[e--])
            temp = 0;
        else
        {
            temp = 1;
            break;
        }
    }
    if (temp == 0)
        return 0; 
        else
        return 1;
}
int main()
{
    string a;
    cout<<"Enter the string ::\n";
    cin>>a;
    if(checkpal(a))
    cout<<"Given string is palindrome..";
    else
    cout<<"Sorry given string is not palindrome !";
    return 0;
}