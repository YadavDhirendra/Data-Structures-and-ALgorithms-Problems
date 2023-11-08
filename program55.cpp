// Write a program to print no. of prime numbers less than n.
#include<bits/stdc++.h>
using namespace std;
bool primeno(int n)
{   

    for (int i = 2; i < n; i++)
    {
        if(n%i==0)
        return 0;   
    }
    return 1;
}
int main()
{
    int n,count=0;
    cout<<"Enter the number ::\n";
    cin>>n;
    for (int i = 2; i < n; i++)
    {
      if(primeno(i))  
      count++;
    }
    cout<<"The no. of prime numbers less than "<<n<<" is "<<count;
    return 0;
}