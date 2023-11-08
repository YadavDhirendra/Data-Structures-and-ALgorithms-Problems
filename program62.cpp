//Minimize and maximize between the diffrence of heights.
/*Given an array a[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.
->Increase the height of tower by K
->Decrease the height of tower by K(you can perform this operation only if the height of tower is greater than or equal to K)

Find out the min. possible diff. bet. the ht. of shortest and tallest towers after you have modified each tower.
Example :
Input :
K=2,N=4
A[]={1,5,8,10}
Output :
5
Explanation :
The array can be modified as {3,3,6,8}. The diff bet. largest and the smallest is 8-3=5
*/
#include <bits/stdc++.h>
using namespace std;
int getmindiff(int a[], int n, int k)
{
    sort(a, a + n);
    int ans = a[n - 1] - a[0];
    int smallest = a[0] + k;
    int largest = a[n - 1] - k;
    int mi, ma;
    for (int i = 0; i < n - 1; i++)
    {
        mi = min(smallest, a[i + 1] + k);
        ma = min(largest, a[i + 1] - k);
        if (mi < 0)
            continue;
        else
            ans = min(ans, ma - mi);
    }
    return ans;
}
int main()
{
    int a[100], n, k;
    cout << "Enter the no. of towers ::\n";
    cin >> n;
    cout << "Enter the height to be modified in towers ::\n";
    cin >> k;
    cout << "Enter the height of towers ::\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "The min. diff bt the largest and smallest towers is " << getmindiff(a, n, k);
    return 0;
}