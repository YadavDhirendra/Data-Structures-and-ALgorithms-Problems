//Write a function that taken as an unsigned integer and returns the number of 1's bits it has (also known as The Hamming Weight).
#include<iostream>

using namespace std;
int main()
{
    unsigned int n;
    cout<<"Enter an unsigned integer :\n";
    cin>>n;
    int a[100],i=0,x=n;
    while (1)
    {
       a[i] =x%2;
       x=x/2;
       if(x==0)
       break;
       i++;

    }
    int temp=0;
    for (int j = i; j >=0; j--)
    {
      if (a[j]==1)
      {
          temp++;
      }
        
    }
    cout<<"The number of 1's bits in "<<n<<" is "<<temp<<".";
    return 0;
}