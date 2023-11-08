/* Write a program to print 
            1
        2   2
    3   3   3
4   4   4   4 */
#include<iostream>

using namespace std;
int main()
{
    int n=4;
    for (int i = 0; i < n; i++)
    {
     for (int j = n; j >i; j--)
    cout<<"  ";
     for (int k = 0; k < i+1; k++)
     cout<<i+1<<" ";
     cout<<endl;
      
    }
    
    return 0;
}