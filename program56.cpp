//Sieve of Eratosthenes
//1.Mark every no. as a prime no.
//2.Unmark the noumbers that comes in table of any previous no.
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,count=0;
    cout<<"Enter the no. ::"<<endl;
    cin>>n;
    vector<bool> prime(n,true);
    prime[0]=0,prime[1]=0;
    for (int i = 2; i < n; i++)
    {
      if(prime[i])  
      count++;

    for (int j = 2*i; j < n; j+=i)
    {
        prime[j]=0;
    }
    
    }
    cout<<"The no. of prime numbers less than "<<n<<" is "<<count;
    return 0;
}