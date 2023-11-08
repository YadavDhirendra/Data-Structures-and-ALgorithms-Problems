/*Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that he can take down forests like Wildfir. However, MIrko is only allowed to cut a single row of trees.
MIrko;s machine works as follows : Mirko sets a height parameter H(in metres) and the machine raises a great sawblade to that height and cuts off all tree parts height than H(of course,trees not higher than H remains intact).Mirko then takes the parts that were cut off. For example, if the tree row contain treeswith the heights of 20,15,10,17 metres , and Mirko raises his sawblades to 15 metres respectively, While Mirko will take 5 metres off the first tree and 2 metres off the fourth tree(7 metres of wood in total).
    Mirko is ecologically minded, So he doesn't want to cut off more than neceassary .That's why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.*/
#include <iostream>
#include<algorithm>
#define int long long int
using namespace std;

bool ispossible(int a[],int n,int m,int mid)
{
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        if(a[i]>mid)
        ans=ans+(a[i]-mid);
    }
    if(ans>=m)
    return true;
    else
    return false;
}
int EKO(int a[],int n,int m)
{
    sort(a,a+n);
    int s=1,sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=a[i];
    }
    int e=sum,ans=0;
    while (s<=e)
    {
        int mid = s+(e-s)/2;
        if(ispossible(a,n,m,mid))
        {
            ans=mid;
            s=mid+1;
        }
        else
        { 
            e=mid-1;
        }
    }
   return ans;     
}
int32_t main()
{
    int a[100],n,m;
    cout<<"Enter the no. of trees :\n";
    cin>>n;
    cout<<"Enter the required amount of wood :: ";
    cin>>m;
    cout<<"Enter the length of each tree ::\n";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"The maximum height at wich Mirko cut the trees is "<<EKO(a,n,m);
    return 0;
}