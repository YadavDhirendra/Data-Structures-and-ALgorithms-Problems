//String compression
//example : i/p = "aabbccc"
// o/p = "a2b2c3" if it occurs only 1 time then dont take 1 in string
#include<bits/stdc++.h>
using namespace std;
int compress(string s)
{   
    int i=0,n=s.length();
    int ansindex=0;
    while (i<n)
    {
       int j=i+1;
       while (s[i]==s[j] && j<n)
       {
           j++;
       }
        //yaha kab aaoge
        //ya to string khatam hogya
        //ya new/diff char encounter hua h

        //old character store krlo
        s[ansindex++]=s[i];

        int count = j-i;
        if (count>1)
        {   //converting count into string
            string cnt = to_string(count);
            for(int i=0;i<cnt.length();i++)
            {
                s[ansindex++]=cnt[i];
            }
        }
        i=j;
    }
    return ansindex;

}
int main()
{
    string s= "aabbccc";
    cout<<"The comprssion of string is : "<<compress(s);
    return 0;
}