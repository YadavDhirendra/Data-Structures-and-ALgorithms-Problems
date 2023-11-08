//phone keypad problem by recursion
//Example : i/p : "23"
//o/p : ["ad","ae","af","bd","be","bf","cd","ce","cf"]
#include<bits/stdc++.h>
using namespace std;

void Phonekeypad(string str,vector<string> &ans,string output,vector<string> mapping,int index)
{
    //base case
    if(index>=str.length()){
    ans.push_back(output);
    return ;
    }

    //changing str numeric char to numeric value
    int digit = str[index]- '0';

    //digit points to which mapping
    string value = mapping[digit];

    //baaki ye dekh lega
    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        Phonekeypad(str,ans,output,mapping,index+1);
        output.pop_back();
    }
    

}

int main()
{
    string str = "23";
    vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    string output;
    Phonekeypad(str,ans,output,mapping,0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
    
    return 0;
}