//replace spaces with @40
#include<bits/stdc++.h>
using namespace std;

void replacespaces(string &str)
{   
    string s="@40";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i]==' ')
        {
            str.erase(str.begin()+i);
            str.insert(i,s);
        }
        
    }
    
}

int main()
{
    string str = "My name is Yadav";
    replacespaces(str);
    cout<<str;
    return 0;
}