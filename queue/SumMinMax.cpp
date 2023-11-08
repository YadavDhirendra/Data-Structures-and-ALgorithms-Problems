//Sum of minimum and maximum elements of all subarrays of size k(just similar to window ques)
#include<bits/stdc++.h>
using namespace std;

int SumMinMax(int *arr,int n,int k)
{
    //create max and min stacks
    deque<int> mini(k);
    deque<int> maxi(k);

    int ans = 0;
    
    //step 1.fetch max and min of first k sized subarray
    for (int i = 0; i < k; i++)
    {
       while (!maxi.empty() && arr[maxi.back()] <= arr[i])
       maxi.pop_back();

       while(!maxi.empty() && arr[mini.back()] >= arr[i])
       mini.pop_back();

       maxi.push_back(i);
       mini.push_back(i);
       
    }
    
    ans += arr[maxi.front()] + arr[mini.front()];
    
    //for remaining elements
    for (int i = k; i < n; i++)
    {
        //next window
        
        //removal
        while(!maxi.empty() && i-maxi.front()>=k)
        maxi.pop_front();

        while(!mini.empty() && i-mini.front()>=k)
        mini.pop_front();

        //addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
        maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
        mini.pop_back();


        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main()
{
    int arr[] = {2,5,-1,7,-3,-1,-2};
    int n = 7;
    int k = 3;
    cout<<"Sum of Min and Max of elements of all subarrays of size "<<k<<" is : "<<SumMinMax(arr,n,k)<<endl;
    return 0;
}