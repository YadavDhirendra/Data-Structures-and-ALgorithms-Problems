//MOve all negative elements to one side of array
#include<bits/stdc++.h>
using namespace std;
void moveneg(int a[],int n)
{
    //insertion sort
   int i=0;
   while(i<n)
   {
        int j=i-1;
        int temp=a[i];
        while (j>=0)
        {
            if(a[j]>temp)//Shift by one position to create a vacancy for ith element
            a[j+1]=a[j];

            else
            break;
            j--;
        }
        a[j+1]=temp;
        i++;

   }
    
    
    
}
int main()
{
    int a[100]={1,-3,0,-8,2,-9};
    moveneg(a,6);
    for (int i = 0; i < 6; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}