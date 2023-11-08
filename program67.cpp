//Jagged array in dynamic memory
#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int row;
    cout<<"Enter the no. of rows ::\n";
    cin>>row;
    int *numbers=new int[row];
    int **array=new int*[row];
    for (int i = 0; i < row; i++)
    {   
        cout<<"Enter the no. of column for "<<i+1<<"th row ::\n";
        cin>>numbers[i];
        array[i]=new int[numbers[i]];
    }
    cout<<"Enter the elements of jagged array ::\n";
    for (int i = 0; i < row; i++)
    {   
        cout<<"Row : "<<i<<" Enter values :"<<numbers[i]<<endl;
        for (int j = 0; j < numbers[i]; j++)
        {
            cin>>array[i][j];
        }
        
    }
    cout<<"Showing all the Inputed data in matrix form ::\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < numbers[i]; j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Deleting the array...\n";
    for (int i = 0; i < row; i++)
    {
        delete [] array[i];
        }
        delete [] array;
        cout<<"done!"
    
    return 0;
}