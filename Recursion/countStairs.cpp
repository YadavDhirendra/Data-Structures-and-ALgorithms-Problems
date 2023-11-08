//count ways to reach n-th stairs 
//constraints : Each time u can climb one or two stairs
#include<bits/stdc++.h>
using namespace std;

int noway(int n)
{
    //base condition
    if(n<0)
    return 0;
    if(n==0)
    return 1;

    //recursive relation
    return noway(n-1)+noway(n-2);
}

int main()
{
    int n;
    cout<<"Enter the no. of stairs :\n";
    cin>>n;
    cout<<"The no of ways for "<<n<<" stairs are : "<<noway(n);
    return 0;
}