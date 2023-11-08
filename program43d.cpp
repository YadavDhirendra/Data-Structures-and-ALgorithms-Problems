//move zeroes
#include <bits/stdc++.h>
using namespace std;
void movezero(int a[], int n)
{
   int i=0;
   for (int j = 0; j < n; j++)
   {
       if (a[j]!=0)
       {
           swap(a[j],a[i++]);
       }
       
   }
   
}
void print(int a[],int n)
{   
    cout<<"The elements of array ::\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}
int main()
{
    int a[100], n;
    cout << "Enter the size of array ::" << endl;
    cin >> n;
    cout<<"Enter the elements of array ::\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    movezero(a,n);
    print(a,n);
    return 0;
}