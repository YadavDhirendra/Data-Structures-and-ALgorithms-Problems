/* Write a program to print 
1   1   1   1
    2   2   2
        3   3
            4 */
#include<iostream>

using namespace std;
int main()
{   
    int n=4;
    for (int i = 0; i < n; i++)
    {
       for (int k = n; k >n-i ; k--)
       cout<<"  ";
       for (int j = i; j < n; j++)
       cout<<i+1<<" ";
       cout<<endl;
       
        
    }
    
    return 0;
}