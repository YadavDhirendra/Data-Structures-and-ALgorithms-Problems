//Write a program to return the difference of product and sum of digits of integer n.
#include<iostream>
int product(int n);
int sum(int n);
using namespace std;
int main()
{
    int n,product=1,sum=0;
    cout<<"Enter any integer :\n";
    cin>>n;
    int x=n;
    int y=n;
    while (1)
    {
        sum+=x%10;
        x=x/10;
        if(x==0)
        break;
    }
    while (1)
    {
        product*=y%10;
        y=y/10;
        if(y==0)
        break;
    }
    cout<<"The diff. bet. the product and sum of digit of "<<n<<" is "<<product-sum;
    return 0;
}
