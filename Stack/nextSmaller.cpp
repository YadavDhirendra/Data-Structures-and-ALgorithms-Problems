//Next smaller element in an array
#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> arr)
{   
    int n = arr.size();
    // cout<<n<<endl;
    stack<int> s;
    s.push(-1);
    vector<int> ans = arr;
    for (int i = n-1; i >=0; i--)
    {

        int curr = arr[i];
        while (s.top()>=curr)
        {
            s.pop();
        }

        //ans is stack ka top
        ans[i]=s.top();
        s.push(curr);   
    }
 return ans;
}

int main()
{
    vector<int> arr = {2,1,4,3};
    vector<int> ans = nextSmaller(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}