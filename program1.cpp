//Write a program to check whether a character is in lowercase, uppercase and numeric.
#include<iostream>

using namespace std;
int main()
{
    char ch;
    cout<<"Enter any character except special symbols :" <<endl;
    cin>>ch;
    if (ch>64 && ch<91)
    {
        cout<<ch<<" is an Uppercase letter"<<endl;
    }
    else if (ch>96 && ch<124)
    {
        cout<<ch<<" is a lowercase letter"<<endl;
    }
    else if (ch>47 && ch<58)
    {
        cout<<ch<<" is a number"<<endl;
    }
    
    return 0;
}