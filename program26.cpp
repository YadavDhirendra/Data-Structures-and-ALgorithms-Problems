//Program based on Binary Search
#include<iostream>
using namespace std;
int binarysearch(int a[],int size,int key)
{
    int start=0,end=size-1;
    while (start<=end)
    {
    int mid=start+(end-start)/2;
        if (a[mid]==key)
        {
            return mid;
        }
        
        else if(a[mid]>key)
        {
            end=mid-1;
            
        }
        else if(a[mid]<key)
        {
            start=mid+1;
           
        }
        
    }
    return -1;
    
}
int main()
{
    int even[]={2,6,16,18,20};
    int odd[]={1,5,7,17};
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    cout<<"The index of 16 in even is "<<binarysearch(even,5,16)<<endl;
    cout<<"The index of 17 in odd is "<<binarysearch(odd,4,17)<<endl;
    cout<<"The index of 10 in arr is "<<binarysearch(arr,10,10)<<endl;
    return 0;
}