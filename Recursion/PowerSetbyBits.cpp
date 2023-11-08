//Power set by bits manipulation
#include<bits/stdc++.h>
using namespace std;


void Powerbits(vector<int> nums)
{
    int pow_set_size = pow(2,nums.size());

    for (int counter = 0; counter < pow_set_size; counter++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if(counter & (1<<j))
            cout<<nums[j]<<" ";
        }
        cout<<endl;
    }
    
}

int main()
{
    vector<int> nums={1,2,3};
    Powerbits(nums);
    return 0;
}