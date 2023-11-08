//Write a program to print the integer got when we flip all '0' to '1' and all '1' to '0'.
#include<iostream>

using namespace std;
int main()
{
    int n,mask=0,i=0;
    cout<<"Enter any integer :\n";
    cin>>n;
    int x=n;
    //for knowing position of rightmost 1 in integer
    while (x!=0)
    {
        x=x>>1;
        i++;
    }
    cout<<"value of i is = "<<i<<endl;
    //for making mask by inserting i times '1' in 0
    while (i>0)
    {
        mask=(mask<<1);
        mask=mask|1;
        i--;
    }
    
    cout<<"The value of mask is = "<<mask<<endl;
    cout<<"Value of ~"<<n<<" is = "<<~n<<endl;
    cout<<"The required compilement of integer "<<n<<" is = "<<(mask&(~n));
    
    return 0;
}