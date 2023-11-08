//Problem : Given an array of length of 'N' , where each element denotes the position of a stall.Now you have 'N' stalls and an integer 'K' which denotes the number of cows that are aggressive. To prevent the cows from hurting each other. You need to assign the cows to the stalls, such that minimum distance between any two of them is as large as possible, Return the largest minimun diistance.
#include<iostream>
#include<algorithm>
using namespace std;

bool ispossible(int a[],int n,int k , int mid)
{
    int cowcount=1;
    int lastpos=a[0];
    for (int i = 0; i < n; i++)
    {
        if(a[i]-lastpos>=mid)
        {
            cowcount++;
        lastpos=a[i];

        }
        if(cowcount==k)
        {
        return true;
        }

    }
    return false;
}
int position(int a[],int n,int k)
{   
      
    sort(a,a+n);
    
    
    int s=0,ans=-1;//Search Space
    
   int e=a[n-1]-a[0];
  
    while (s<=e)
    {
        int mid = s+(e-s)/2;
        if(ispossible(a,n,k,mid))
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
int main()
{
    int a[100],n,k;
    cout<<"Enter the size of array :\n";
    cin>>n;
    cout<<"Enter the no. of cows ::\n";
    cin>>k;
    cout<<"Enter the no. of stalls :\n";
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<"The largest distance at which the cows can be placed is "<<position(a,n,k);
    return 0;
}