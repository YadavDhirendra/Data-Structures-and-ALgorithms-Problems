//Problem : You are given an array of size 'N' containing each element between 1 and N-1 atleast once. There is a number that present in the array twice. Your task is to find the duplicate integer value present in the array.
#include <iostream>
using namespace std;
int duplicate(int a[], int size)
{   
    int i,j;
    for ( i = 0; i < size; i++)
    {
        int temp = 0;
        for ( j = i + 1; j < size; j++)
        {
            if (a[i] == a[j])
            {
                temp = 1;
                break;
            }
        }
        if(temp==1)
        break;
    }
return a[i];
}
int main()
{
    int arr[100], size;
    cout << "Enter the size of array :\n";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int x= duplicate(arr,size);
    cout<<"The duplicate element is "<<x;
    return 0;
}