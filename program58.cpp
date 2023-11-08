//Write a program to find gcd and lcm of two numbers.
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;

    if (b == 0)
        return a;

    while (a != b)
    {
        if (a == 0)
            return b;

        if (b == 0)
            return a;
        if (a > b)
            a = a % b;
        else
            b = b % a;
        
    }
    
}

int main()
{
    int a, b;
    cout << "Enter the 1st no. ::\n";
    cin >> a;
    cout << "Enter the 2nd no. ::\n";
    cin >> b;
    int g = gcd(a, b);
    int l = (a * b) / gcd(a, b);
    cout << "The GCD of " << a << " and " << b << " is " << g << endl;
    cout << "The LCM of " << a << " and " << b << " is " << l << endl;

    return 0;
}