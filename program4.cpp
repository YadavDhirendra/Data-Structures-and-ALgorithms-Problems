#include<iostream>

using namespace std;
int main()
{   
    int n;
    cout<<"Enter the no. of rows"<<endl;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n-1; j++)
       cout<<" ";
        
        for (int k = 0; k <=i ; k++)
        cout<<"* ";

        cout<<endl;
    }
    
    return 0;
}