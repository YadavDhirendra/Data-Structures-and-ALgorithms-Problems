//permutation of string by recursion
//Example : i/p : "abc"
//o/p : ["abc","acb","bca","cab","cba"]
#include <bits/stdc++.h>
using namespace std;

void Permutation(string str, vector<string> &ans, int index)
{
    //base case
    if (index >= str.length())
    {   
        ans.push_back(str);
        return;
    }

    for (int j = index; j < str.length(); j++)
    {
        swap(str[index],str[j]);
        Permutation(str,ans,index+1);
        //backtrack
        swap(str[index],str[j]);
    }
    
   
}

int main()
{
    string str = "abc";
    vector<string> ans;
    Permutation(str, ans, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}