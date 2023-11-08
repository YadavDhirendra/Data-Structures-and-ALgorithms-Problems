//Write a program to print the binary value of -ve number
#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    int n, ans = 0, i = 0, a[32],carry=1;
    cout << "Enter any -ve number :\n";
    cin >> n;

    int x = -n;

    while (i < 32)
    {
        int bit = x & 1;
        //for 1's compliment
         if (bit == 1)
            a[i] = 0;
        else
            a[i] = 1;
        i++;
        x = x >> 1;
    }
    cout << "The binary value of " << n << " is :";
    
    //for 2's compliment
    for (int j = 0; j <i ; j++)
    {
        if (a[j]==1 && carry==1)
        {
           a[j]=0; 
        }
        else if(a[j]==0 && carry==1)
        {
            a[j]=1;
            carry=0;
        }
        else
        continue;

    }
    
    for (int j = i-1; j >= 0; j--)
    {
        cout<<a[j];
    }
    

    return 0;
}