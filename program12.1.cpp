//Write a function that taken as an unsigned integer and returns the number of 1's bits it has (also known as The Hamming Weight).
#include <iostream>

using namespace std;
int main()
{
    int n, temp = 0;
    cout << "Enter any positive number :\n";
    cin >> n;
    while (n!=0)
    {
        int bit =n&1;
        if (bit == 1)
        {
            temp++;
           
        }
      n= n>>1;
    }
    cout<<"The no. of 1's bits = "<<temp<<".";
    return 0;
}