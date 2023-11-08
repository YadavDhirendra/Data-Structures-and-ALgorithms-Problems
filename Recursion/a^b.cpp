//wap to calculate a^b by using love babbar formula
//if b is even a^b = (a^b/2 * a^b/2)
//if b is odd a^b = a * (a^b/2 * a^b/2)
#include<bits/stdc++.h>
using namespace std;

int Power(int a,int b)
{
    //base case
    if(b==0)
    return 1;
    if(b==1)
    return a;

    int ans = Power(a,b/2);

    //recursive call
    if(b%2==0)
    return ans*ans;
    else
    return a*ans*ans;
}

int main()
{
    int a,b;
    cout<<"Give the value of a and b :\n";
    cin>>a>>b;
    cout<<"The "<<a<<" power "<<b<<" is : "<<Power(a,b);
    return 0;
}
