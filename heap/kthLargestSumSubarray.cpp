//KTh  Largest SUm Subarray
#include<bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr,int k)//O(n^2logn) algo
{
    vector<int> sumStore;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum +=arr[j];
            sumStore.push_back(sum);
        }
        
    }
    sort(sumStore.begin(),sumStore.end());

    return sumStore[sumStore.size()-k];//as 1st largest -> n-1 then kth largest -> n-k
}

int getkThlargest2(vector<int> &arr,int k)//O(n^2) algo
{
    int n = arr.size();
    priority_queue<int,vector<int>,greater<int>> mini;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum +=arr[j];
            if(mini.size()<k)
            {
                mini.push(sum);
            }
            else{
                if(sum>mini.top())
                {
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
        
    }
    return mini.top();
}

int main()
{
    vector<int> arr = {0,1,2};
    cout<<"Enter the value of K"<<endl;
    int k;
    cin>>k;
    cout<<"THe "<<k<<"th largest sum of subarray is : "<<getKthLargest(arr,k)<<endl;
    cout<<"THe "<<k<<"th largest sum of subarray is : "<<getkThlargest2(arr,k)<<endl;
    return 0;
}