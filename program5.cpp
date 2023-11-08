/*Write a program to print the pattern
*   *   *   *
*   *   *
*   *
*
*/
#include<iostream>

using namespace std;
int main()
{   
    int n=4;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        cout<<"* ";

        for (int k = i; k < n; k++)
        cout<<" ";

        cout<<endl;
        
        
    }
    
    return 0;
}