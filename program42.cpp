//merge two sorted array in the first array
#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int n1, int b[], int n2)
{
    int j =0;
    for (int i = n1; i < n1 + n2; i++)
    {
        a[i] = b[j++];
    }
    int m = n1 + n2;
    //sorting of array(bubble sort)
    for (int i = 0; i < m-1; i++)
    {
      int k=0;
      for (int j = 1; j < m-i; j++)
      {
          if(a[k]>a[j])
          swap(a[k],a[j]);
          k++;
      }
        
    }
}
void print(int a[],int n)
{
    cout<<"The elements of array are ::\n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
}
int main()
{
    int a[] = {1, 3, 5, 7, 0, 0, 0}, n1 = 4, b[] = {2, 4, 6}, n2 = 3;
    merge(a,n1,b,n2);
    print(a,n1+n2);
    return 0;
}