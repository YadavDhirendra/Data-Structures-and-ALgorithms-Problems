/* Given a non-negative integer x, compute and return the square root of x with th ehelp of Binary Search. Since the return type is an integer, the decimal digits are truncated and only the integral part of the result is returned.*/
#include <iostream>
using namespace std;

int squareroot(int num)
{
    int s = 0, e = num, ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (mid * mid == num)
            return mid;

        else if (mid * mid > num)
            e = mid - 1;

        else if (mid * mid < num)
        {
            ans=mid;
            s = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int num;
    cout << "Enter any integer :\n";
    cin >> num;
    cout<<"The square root of "<<num<<" is "<<squareroot(num);
    return 0;
}