//Jagged array in static memory
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row0[100]={0,1,2};
    int row1[100]={6,4};
    int row2[100]={1,7,6,8,9};
    int row3[100]={5};
    int *jagged[4]={row0,row1,row2,row3};
    int size[4]={3,2,5,1},k=0;

    for (int i = 0; i < 4; i++)
    {   
        int *ptr=jagged[i];
        for (int j = 0; j < size[k]; j++)
        {
         cout<<ptr[j]<<" ";   
        }
        k++;
        cout<<endl;
    }
    

    return 0;
}