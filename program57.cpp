//Segmented sieve
//Given a number n,print all prime number smaller than n.
//e.g.,10 = 2,3,5,7
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number ::\n";
    cin>>n;
    cout<<"The prime no. less than "<<n<<" are :: "<<endl;
    vector<bool> prime(n,true);
    for (int i = 2; i < n; i++)
    {
        if(prime[i])
        cout<<i<<" ";

        for (int j = 2*i; j < n; j+=i)
        {
           prime[j]=0; 
        }
        
    }
    
    return 0;
}