//Say digits
//example i/p = 412
//o/p = four one two
#include<bits/stdc++.h>
using namespace std;

void saydigit(int n,string arr[])
{
    //base condition
    if(n==0)
    return ;
    int digit = n%10;
    n = n/10;
    //recursive call
    saydigit(n,arr);
    

    cout<<arr[digit]<<" ";

}

int main()
{
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int n ;
    cout<<"Enter the number :\n";
    cin>>n;
    saydigit(n,arr);
    return 0;
}