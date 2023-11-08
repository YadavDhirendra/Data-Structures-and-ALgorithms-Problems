//Subsequences of string just like subsets by using recursion
#include<bits/stdc++.h>
using namespace std;

void subsequences(vector<string> &ans,string str,string output,int i)
{
    //base case
    if(i>=str.size())
    return ;

    //exclude kr do bhai
    subsequences(ans,str,output,i+1);

    //include kr do bhai
    output.push_back(str[i]);
    ans.push_back(output);
    subsequences(ans,str,output,i+1);
}

int main()
{
    string str="abc";
    vector<string> ans;
    string output;
    subsequences(ans,str,output,0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    
    return 0;
}