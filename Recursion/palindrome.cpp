//check palindrome using recursion
#include<bits/stdc++.h>
using namespace std;

bool checkpalindrome(string str,int i ,int j)
{
    //base case
    if(i>j)
    return 1;

    if(str[i]!=str[j])
    return false;
    else
    return checkpalindrome(str,++i,--j);

}

int main()
{
    string s="malayalam";
    int i=0,j=s.length()-1;
    
    if(checkpalindrome(s,i,j))
    cout<<"Given string is palindrome";
    else
    cout<<"Sorry given string is not palindrome";

    return 0;
}