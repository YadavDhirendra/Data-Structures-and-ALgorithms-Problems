//Write a program to swap array's alternate elements.
#include <iostream>
using namespace std;
void swapp(int a[], int size)
{
   for (int i = 0; i+1 < size; i+=2)
   {
//        int temp=a[i];
//        a[i]=a[i+1];
//        a[i+1]=temp;
    swap(a[i],a[i+1]);
   }
   
}
void print(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{   
    int n;
    cout<<"Enter the size of array :\n";
    cin>>n;
    int a[100] ;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    swapp(a, n);
    print(a, n);
    return 0;
}