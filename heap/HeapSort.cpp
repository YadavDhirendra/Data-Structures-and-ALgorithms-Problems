//Heap sort
#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size = 0;

    void insert(int val)
    {   
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index>1)
        {
            int parent = index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else
            return;
        }    
    }

    void print()
    {
        cout<<"printing Heap :"<<endl;
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;  
    }

    void deletion()
    {
        //check for empty
        if(size == 0)
        {
            cout<<"Nothing to delete"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i<=size)
        {   
            
            int left = 2*i;
            int right = 2*i+1;

            if(left<=size && arr[i]<arr[left])
            {
                swap(arr[left],arr[i]);
                i = left;
            }
            else if(right<=size && arr[i]<arr[right])
            {
                swap(arr[right],arr[i]);
                i = right;
            }
            else
            return;
        }
        
    }
};

void heapify(int arr[],int n,int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

   if(left<=n && arr[left]>arr[largest])
   largest = left;
   
   if(right<=n && arr[right]>arr[largest])
   largest = right;

   if(largest != i)
   {
       swap(arr[largest],arr[i]);
       heapify(arr,n,largest);
   }
       
}

void heapSort(int arr[],int n)
{
    int size = n;

    while (size>1)
    {
        //step 1.swap first and last
        swap(arr[size],arr[1]);
        
        //step 2
        size--;

        //step 2
        heapify(arr,n,1); 
    }
    
}

int main()
{
    int arr[6] = {-1,54,53,55,52,50};
    //heap creation
    int n = 5;
    for (int i = n/2; i >0; i--)
    {
        heapify(arr,n,i);
    }
    cout<<"printing the heapified array :"<<endl;
    for (int i = 1; i <=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapSort(arr,n);
    cout<<"Printing the array after heap sort :"<<endl;
    for (int i = 1; i <=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}