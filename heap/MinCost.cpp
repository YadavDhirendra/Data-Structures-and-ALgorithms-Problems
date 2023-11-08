//Minimum cost of ropes
//There are given N ropes of different lengths,we need to connect these into one rope.
//The cost to connect two ropes is equal to sum of their lengths.The task is to connect
//rope with min cost
#include<bits/stdc++.h>
using namespace std;

long long minCost(long long arr[],long long n)
{
    //creating a min heap
    priority_queue<long long,vector<long long>,greater<long long>> pq;
    int cost = 0;

    for (int i = 0; i < n; i++)
    {
      pq.push(arr[i]);
    }
    

    while (pq.size()>1)
    {
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        int sum = a+b;
        cost +=sum;

        pq.push(sum);
    }
    return cost;
}

int main()
{
    long long arr[] = {4,3,2,6};
    long long n = 4;
    cout<<"The Min cost is : "<<minCost(arr,n)<<endl;
    return 0;
} 