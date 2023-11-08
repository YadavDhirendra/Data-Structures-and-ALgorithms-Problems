//First Non-repeating characters in a stream
#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeat(string A)
{
    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        //increase count
        count[ch]++;

        //queue me push karo
        q.push(ch);

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                //repeating character
                q.pop();
            }
            else
            {
                //non-repeating char
                ans.push_back(q.front());
                break;
            }
        }

        if (q.empty())
            ans.push_back('#');
    }
    return ans;
}
string FirstNonRepeat2(string A)
{
    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        //increase count
        count[ch]++;

        if (count[ch] > 1)
            ans.push_back('#');
        else
            ans.push_back(ch);
    }

    return ans;
}

int main()
{
    string A = "aabc";
    string B = "zz";
    string s = FirstNonRepeat(A);
    string s1 = FirstNonRepeat2(B);
    cout << s << endl;
    cout << s1 << endl;
    return 0;
}