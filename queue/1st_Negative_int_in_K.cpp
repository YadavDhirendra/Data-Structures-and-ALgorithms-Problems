//First negative integer in window of size k
#include <iostream>
#include <queue>

using namespace std;

vector<int> NegIntInK(long long int *arr, int n, int k)
{
    vector<int> ans;
    deque<int> dq;

    //Step 1.find 1st negative integer for first k window
    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }

    //store answer of first k sized window
    if (dq.size() > 0)
        ans.push_back(arr[dq.front()]);
    else
    {
        ans.push_back(0);
    }

    //for remaininng window
    for (int i = k; i < n; i++)
    {
        //removal of previous first neg int
        if (!dq.empty() && i - dq.front() >= k) //logic to maintain K sized window
        {
            dq.pop_front();
        }

        //addition
        if(arr[i]<0)
        dq.push_back(i);

        //ans store
        if(dq.size()>0)
        ans.push_back(arr[dq.front()]);
        else
        ans.push_back(0);
    }

    return ans;
}

int main()
{
    long long int A[] = {-8, 2, 3, -6, 10};
    int N = 5, K = 2;
    vector<int> ans = NegIntInK(A, N, K);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}