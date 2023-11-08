//reference variable
#include<bits/stdc++.h>
using namespace std;
void update(int &j)
{
    j=3;
}
int& upd(int n)
{
     int a=5;
    int &ans=a;
    return ans;
}
int main()
{
    int i=5;
    cout<<"Before "<<i<<endl;
    update(i);
    cout<<"After "<<i<<endl;
    int &ans=upd(i);
    cout<<ans;
    return 0;
}