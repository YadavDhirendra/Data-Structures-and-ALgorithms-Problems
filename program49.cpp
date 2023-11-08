//print the sum of 2D array in row wise and column wise also find largest row and column
#include <bits/stdc++.h>
using namespace std;
//printing sum row wise
void sumrow(int m, int n, int a[][100])
{
    int k, maxi = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        cout << "Sum of " << i << "th row is " << sum << endl;
        if (maxi < sum)
        {
            maxi = sum;
            k = i;
        }
    }

    cout << "The largest row of given 2D array is " << k << endl;
}

//printing sum column-wise
void sumcolumn(int m, int n, int a[][100])
{   
    int k,maxi=INT_MIN;
    for (int i = 0; i < n; i++)
    {

        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += a[j][i];
        }
        if (maxi < sum)
        {
            maxi = sum;
            k = i;
        }
        cout << "sum of " << i << "th column is " << sum << endl;
    }
   
    cout << "The largest column of given 2D array is " << k << endl;
}
int main()
{
    int a[100][100], m, n;
    cout << "Enter the no. of row ::\n";
    cin >> m;
    cout << "Enter the no. of columns ::\n";
    cin >> n;
    cout << "Enter the elements of array ::\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    sumrow(m, n, a);
    sumcolumn(m, n, a);
    return 0;
}