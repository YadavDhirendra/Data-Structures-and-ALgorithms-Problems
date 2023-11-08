/* Write a program to print
            1
        1   2   1
    1   2   3   2   1
1   2   3   4   3   2   1 */
#include <iostream>

using namespace std;
int main()
{
    for (int i = 1; i < 5; i++)
    {
        for (int k = 5; k > i; k--)
            cout << "  ";
        int n = 1;
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            if (j > (i + 2) / 2)
            {
                if (i == 2)
                {
                    cout << n - 2;
                    continue;
                }
                cout << n << " ";
                --n;
            }
            else
            {
                cout << n << " ";
                n++;
            }
        }
        cout << endl;
    }

    return 0;
}