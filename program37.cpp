#include<bits/stdc++.h>

using namespace std;

bool ispossible(int a[],int n,int m,int mid)
{   
    int ans[100];
    for (int i = 0; i < n; i++)
    {
        int j=1;
        ans[i]=0;
        while (ans[i]+a[i]*j<=mid)
        {
            ans[i]+=a[i]*j;
            m--;
            j++;
        }
        
    }
    int maxi=-1;
    for (int i = 0; i < n; i++)
    {
        maxi=max(maxi,ans[i]);
    }
    if (m<=0 && maxi <=mid)
    {
        return true;
    }
    else
    return false;
    
}
int codingninja(int a[],int n,int m)
{

    sort(a,a+n);
    int s=0,maxi=-1;
    for (int i = 0; i < n; i++)
    {
        maxi=max(maxi,a[i]);
    }
    int e=0,ans=0;
    for (int i = 1; i <= m; i++)//Search space is total time taken by max ranked cook for 'm' dishes
    {
        e=e+(maxi*i);
    }
    
    while (s<=e)
    {
        int mid=s+(e-s)/2;
        if(ispossible(a,n,m,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    
    return ans;
    
}
int main()
{
    int rank[100],n,m;
    cout<<"Enter the no. of cooks ::\n";
    cin>>n;
    cout<<"Enter the rank of cooks :\n";
    for (int i = 0; i < n; i++)
    {
        cin>>rank[i];
    }
    cout<<"ENter the no. of dishes ::\n";
    cin>>m;
    cout<<"The min. time for cooks to make "<<m<<" dishes "<<"is "<<codingninja(rank,n,m);
    return 0;
}