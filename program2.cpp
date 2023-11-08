/* Write a pogram to print pattern below :
A
B   C
C   D   E
D   E   F   G */
#include<iostream>

using namespace std;
int main()
{   
    int n; 
    cout<<"Enter the no. of rows for which you want to seek :"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {    
        char a='A'+i;
        for (int j = 0; j < i+1; j++)
        {
           cout<<a<<"\t";
           a++;
        }
        
        cout<<endl;
    }
    
    return 0;
}