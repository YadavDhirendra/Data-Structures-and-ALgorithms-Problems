//find union and intersection of two sorted array
#include <bits/stdc++.h>
using namespace std;
int u[100],in[100];
int uni(int a[], int m, int b[], int n)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if (a[i] > b[j])
        {
            u[k++] = b[j++];
        }
        else if (a[i] == b[j])
        {
            u[k++] = a[i];
            i++;
            j++;
        }
        else
        {
            u[k++] = a[i++];
        }
    }
    while (i < m)
    {
        u[k++] = a[i++];
    }

    while (j < n)
    {
        u[k++] = b[j++];
    }
    return k;
}
int inter(int a[],int m,int b[],int n) 
{
    int i=0,k=0;
    while (i<m )
    {
        for (int j = 0; j < n; j++)
        {
            if(a[i]==b[j])
            {
                in[k++]=a[i];
                break;
            }
        }
        i++;
    }
    return k;
}
int main()
{
    int a[100], b[100], m, n;
    cout << "Enter the size of 1st array ::\n";
    cin >> m;
    cout << "Enter the elements of 1st array ::\n";
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the size of 2nd array ::\n";
    cin >> n;
    cout << "Enter the elements of 2nd array ::\n";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout<<"The union of above two arrays is ::\n";
    int k=uni(a,m,b,n);
    for (int i = 0; i < k; i++)
    {
        cout<<u[i]<<" ";
    }
    cout<<"\nThe intersection of above two array is ::\n";
    int l=inter(a,m,b,n);
    for (int i = 0; i < l; i++)
    {
        cout<<in[i]<<" ";
    }
    
        return 0;
}