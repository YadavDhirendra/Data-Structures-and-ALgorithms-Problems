//chech if valid palindrome
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
//faltu characters hatane ke liye
bool ifvalid(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 0;
    }
    return 1;
}

//lowercase me karne ke liye
char tolowercase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return ch;
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

int main()
{

    string a="a man, a plan, a canal: Panama";
    string temp = "";
    for (int i = 0; i < a.length(); i++)
    {
        if(ifvalid(a[i]))
        {
            temp.push_back(a[i]);
        }
    }
    
    for (int i = 0; i < temp.length(); i++)
    {
        temp[i]=tolowercase(temp[i]);
    }
     if(checkpal(temp))
    cout<<"Given string is palindrome..";
    else
    cout<<"Sorry given string is not palindrome !";
    return 0;
}