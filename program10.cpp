/*Write a program to print 
1   2   3   4   5   5   4   3   2   1
1   2   3   4   *   *   4   3   2   1
1   2   3   *   *   *   *   3   2   1
1   2   *   *   *   *   *   *   2   1
1   *   *   *   *   *   *   *   *   1 */
#include <iostream>

using namespace std;
int main()
{
    

    //for rows
    int i = 1;
    while (i < 6)
    {
        //for 1st triangle (numeric tirangle)
        int j = 1;
        while (j <= 6 - i)
        {
            cout << j << " ";
            j++;
        }

        //for 2nd triangle(asterik triangle)
        int k = 1;
        while (k < i)
        {
            cout << "* ";
            k++;
        }

        //for 3rd triangle(asterik triangle)
        int m = 1;
        while (m < i)
        {
            cout << "* ";
            m++;
        }

        //for 4th triangle(numeric triangle)
        int l = 6;
        while (l > i)
        {
            cout << l - i << " ";
            l--;
        }

        cout << endl;
        i++;
    }

    return 0;
}