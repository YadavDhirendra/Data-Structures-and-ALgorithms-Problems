//Merge 2 sorted arrays
#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int n1, int b[], int n2, int c[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[i])
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
//if some of the elements of any array are left 
    while (i<n1)
    {
        c[k++]=a[i++];
    }
    while (j<n2)
    {
        c[k++]=b[j++];
    }
    
}
int main()
{
    int a[] = {1, 3, 6, 9}, b[] = {2, 4, 5,7}, c[100];
    merge(a, 4, b, 4, c);
    cout << "The merged array is ::\n";
    for (int i = 0; i < 8; i++)
    {
        cout << c[i] << " ";
    }

    return 0;
}