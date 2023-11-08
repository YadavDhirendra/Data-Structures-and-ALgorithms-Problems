/*Insertion Sort*/
#include <bits/stdc++.h>
using namespace std;
void insertion(int a[], int n)
{
    int i = 0;
    while (i < n)
    {   
        int j=i-1;
        int temp = a[i];
        while (j >= 0)
        {
            if (a[j] > temp) //shift by one position to create a vacancy for sorting element
            {
                a[j + 1] = a[j];
            }
            else
                break;
            j--;
        }
        a[j + 1] = temp;
        i++;
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
    cout << "Enter the size of an array :" << endl;
    cin >> n;
    cout << "Enter the elements of array ::" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insertion(a, n);
    print(a,n);
    return 0;
}