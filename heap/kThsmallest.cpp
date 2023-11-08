//Kth smallest element
#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int r, int k)
{
    priority_queue<int> pq;
    
    //step 1.Insert first k elements in Max heap
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    //step 2.compare elements after k if they are smaller than top then pop and insert
    for (int i = k; i <=r; i++)
    {
        if(arr[i]<pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    //Now top of Max heap is kth smallest
    return pq.top();

    
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = 6;
    int k = 3;
    cout<<"The "<<k<<"th smallest element is "<<kthSmallest(arr,n-1,k)<<endl;

    return 0;
}