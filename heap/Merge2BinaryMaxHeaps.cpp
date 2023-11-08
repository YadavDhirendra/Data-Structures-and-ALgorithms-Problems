//Merge 2 Binary Max Heaps
#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &ans,int n,int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if(left<n && ans[left]>ans[largest])
    largest = left;

    if(right <n && ans[right]>ans[largest])
    largest = right;

    if(largest != i)
    {
        swap(ans[largest],ans[i]);
        heapify(ans,n,largest);
    }
}

vector<int> mergeHeaps(vector<int> &a,vector<int> &b,int n,int m)
{
    //step 1.merge both arrays into one
    vector<int> ans;
    for(auto i:a)
    ans.push_back(i);
    for(auto i:b)
    ans.push_back(i);

    
    //step 2.Build heap using merged array
    int size = ans.size();
    for (int i = size/2-1; i >=0; i--)
    {
        heapify(ans,size,i);
    }
    return ans;
}

int main()
{
    vector<int> a = {10,5,6,2};
    vector<int> b = {12,7,9};
    vector<int> ans = mergeHeaps(a,b,4,3);
    cout<<"The merged Heap : "<<endl;
    for (int i = 0; i < ans.size(); i++)
    
    {
        cout<<ans[i]<<" ";
    }cout<<endl;
    
    return 0;
}