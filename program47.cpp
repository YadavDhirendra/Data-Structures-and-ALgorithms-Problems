//permutation in string
//e.g., ab in eidaboo that's true
#include <bits/stdc++.h>
using namespace std;
bool checkequal(int a[], int b[])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}
bool permutation(string s1, string s2)
{
    int count1[26]={0}, count2[26]={0};
    //counting alphabets of s1 string
    for (int i = 0; i < s1.length(); i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }
    //counting alphabets of s2 in s1 windowsize
    int i = 0, winsize = s1.length();
    while (i < winsize && i < s2.length())
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }
    if (checkequal(count1, count2))
        return 1;
    //now counting for all alphabets in s2 string under s1 windowsize
    while (i < s2.length())
    {   
        //adding new character in new window
        char newchar = s2[i];
        int index = newchar - 'a';
        count2[index]++;
        //removing old character from new window
        char oldchar = s2[i - winsize];
        index = oldchar - 'a';
        count2[index]--;
        i++;
        if (checkequal(count1, count2))
            return 1;
    }
    return 0;
}
int main()
{
    string s1, s2;
    cout << "Enter the first string ::\n";
    getline(cin, s1);
    cout << "Enter the second string ::\n";
    getline(cin, s2);
    if (permutation(s1,s2))
    cout<<"Yup it has a permutation of 2nd string..";
    else
    cout<<"Sorry! it hasn't any permutation of 2nd string..";
    
    return 0;
}