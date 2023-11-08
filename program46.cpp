//add two array just like doing maths in primary classes
#include <bits/stdc++.h>
using namespace std;
void addition(int a[], int m, int b[], int n)
{
    int ans[100], carry = 0, sum = 0;
    int i = m - 1, j = n - 1, k = 0;
    //1st case
    while (i >= 0 && j >= 0)
    {
        sum = a[i--] + b[j--] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans[k++] = sum;
    }
    //2nd case
    while (i >= 0)
    {
        sum = a[i--] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans[k++] = sum;
    }
    //3rd case
    while (j >= 0)
    {
        sum = b[j--] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans[k++] = sum;
    }
    //4th case
    if (carry != 0)
        ans[k++] = carry;

    cout << "The resultant added array is ::\n";
    for (int i = k - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    int a[100], m, b[100], n;
    cout << "Enter the size of 1st array ::" << endl;
    cin >> m;
    cout << "Enter the elements of 1st array ::\n";
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the size of 2nd array ::" << endl;
    cin >> n;
    cout << "Enter the elements of 2nd array ::\n";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    addition(a, m, b, n);

    return 0;
}