//Write a program to reverse any integer.
#include<iostream>
#include<math.h>
int reverse(int n)
{   
    int ans=0,i=0;
    while (n!=0)
    {
        int digit = n%10;
        ans=(ans * 10)+digit;
        i++;
        n=n/10;
    }
    return ans;
}
using namespace std;
int main()
{
    int n;
    cout<<"Enter any integer :\n";
    cin>>n;
    if(n>0)
    cout<<"The reverse of "<<n<<" is "<<reverse(n);
    else
    cout<<"The reverse of "<<n<<" is -"<<reverse(n);

    return 0;
}