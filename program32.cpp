/* Given a non-negative integer x, compute and return the square root of x with the help of Binary Search. */
#include<iostream>
using namespace std;

int sqrtint(int num)
{
    int s=0,e=num,ans=0;
    while (s<=e)
    {
        int mid=s+(e-s)/2;
        if(mid*mid==num)
        return mid;

        else if(mid*mid<num)
        {
        s=mid+1;
        ans=mid;
        }

        else
        e=mid-1;
    }
    
    return ans;
}
double moreprecise(int num, int precision , int tempsol)
{
    double factor =1,ans=tempsol;
    for (int i = 0; i < precision; i++)
    {   
        factor=factor/10;
        for (double j = ans; j*j < num; j=j+factor)
        {
            ans=j;
        }
        
    }
    return ans;
}
int main()
{
    int num,precision;
    cout<<"Enter any integer :: ";
    cin>>num;
    cout<<"Enter the no. of digits upto which u want sqrt :: ";
    cin>>precision;
    int tempsol=sqrtint(num);
    cout<<"Integr sqrt is "<<tempsol<<endl;
    cout<<"The sqaure root of "<<num<<" is :: "<<moreprecise(num,precision,tempsol);
    return 0;
}