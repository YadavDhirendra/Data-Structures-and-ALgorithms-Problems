//Write a program to print the binary value of decimal .
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n, i = 0, ans = 0;
    cout << "Enter any integer :\n";
    cin >> n;
    int x = n;
    while (n != 0)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }
    cout << "The binary of " << x << " is " << ans;
    return 0;
}