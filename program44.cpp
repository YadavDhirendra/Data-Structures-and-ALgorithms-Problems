//rotate the array by k positions
#include <bits/stdc++.h>
using namespace std;
void rotate(int a[], int n, int k)
{
    int c[100];
    for (int i = 0; i < n; i++)
    {
        c[(i + k) % n] = a[i]; //concept :: range of x/n is [0,n-1],where x is any real value for creating loop in which after n-1 index 0 will come
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = c[i];
    }
}
void print(int a[],int n)
{
    cout<<"The elements o farray ::\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}
int main()
{
    int a[100], n, k;
    cout << "Enter the size of array :" << endl;
    cin >> n;
    cout << "Enter the elements of array ::" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the no. of position for rotation ::" << endl;
    cin >> k;
    rotate(a,n,k);
    print(a,n);
    return 0;
}