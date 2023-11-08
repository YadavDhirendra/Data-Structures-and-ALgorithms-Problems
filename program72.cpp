//maximum occuring character
#include<bits/stdc++.h>
using namespace std;

char getmaxoccurance(string str)
{
    int ans[26]={0};
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i]>='a' && str[i]<='z')
        {
            int temp = str[i]-'a';
            ans[temp]++;
        }
    }

    int maxi=-1,res=0,i;
    for ( i = 0; i < 26; i++)
    {
        if (maxi<ans[i])
        {
            maxi=ans[i];
            res=i;
        }
        
    }
   char answer = 'a'+res;
   
   return answer; 
    
}
int main()
{
    string s;
    cout<<"Enter the string :"<<endl;
    cin>>s;
    cout<<"the most occurring char is : "<<getmaxoccurance(s);
    return 0;
}