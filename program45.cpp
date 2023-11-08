//check if array is sorted and rotated
/*concept : if array is rotated and sorted then there will exist 1 pair for which           a[i]>a[i+1] from index 0 to 0 (0-1,1-2,2-3,3-4,...,(n-2)-(n-1),(n-1)-0)*/
#include <bits/stdc++.h>
using namespace std;
bool rotated(int a[], int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            count++;
    }
    //for comparing first and last element for taking as a loop
    if (a[n - 1] > a[0])
        count++;
    if (count <= 1)
        return true;
    else
        return false;
}
int main()
{
    int a[100], n;
    cout << "Enter the size of array ::\n";
    cin >> n;
    cout << "Enter the elements of array ::\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if(rotated(a,n))
    cout<<"Given array is rotated and sorted...";
    else
    cout<<"Sorry ! given array is not rotated and sorted..";
    return 0;
}