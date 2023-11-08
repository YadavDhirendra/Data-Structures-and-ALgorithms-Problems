#include<bits/stdc++.h>
using namespace std;
int add(int *p,int n)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=p[i];
    }
    return sum;
}
int main()
{
    int *ptr=new int[n];
    int n;
    string *c=new string;
    cout<<"Enter the string ::\n";
    getline(cin,*c);
    cout<<*c<<endl;
    cout<<"Enter the size of array ::\n";
    cin>>n;
    cout<<"Enter the elements of array ::\n";
    for (int i = 0; i < n; i++)
    {
        cin>>ptr[i];
    }
    cout<<"The summation of all element is "<<add(ptr,n);
    delete [] ptr;
    return 0;
}