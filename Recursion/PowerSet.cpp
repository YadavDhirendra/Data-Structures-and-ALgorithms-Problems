//Power set using recursion
#include <bits/stdc++.h>
using namespace std;

void subSets(vector<int> nums, vector<vector<int>> &ans, vector<int> output, int i)
{

    //base case
    if (i >= nums.size())
        return;

    //exclude ke liye
    subSets(nums, ans, output, i + 1);

    //include krne ke liye
    output.push_back(nums[i]);
    ans.push_back(output);
    subSets(nums, ans, output, i + 1);
}

int main()
{
    vector<vector<int>> ans;
    vector<int> output;
    vector<int> nums = {1, 2, 3,4};
    subSets(nums, ans, output, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}