//Subsequences of string by bits manipulation
#include<bits/stdc++.h>
using namespace std;

void subsequences(string str)
{
    int pow_set_size = pow(2,str.size());

    for (int counter = 0; counter < pow_set_size; counter++)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if(counter & (1<<i))
            cout<<str[i]<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    string str="abc";
    subsequences(str);
    return 0;
}