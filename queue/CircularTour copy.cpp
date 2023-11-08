//Circular Tour
/*Suppose there is a circle.There are N petrol pumps on that circle.You will be given two sets of data.
1.The amount of petrol that every petrol pump has.
2.Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
*/
#include<bits/stdc++.h>
using namespace std;

struct petrolPump{
    int petrol;
    int distance;
};

int Circulartour(petrolPump p[],int n)
{
    int balance = 0;
    int deficit = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if(balance < 0)
        {
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }

    if(balance + deficit >= 0)
    return start;
    else 
    return -1;
    
}

int main()
{
    petrolPump p[4];

    //petrol initialization
    p[0].petrol = 4;
    p[1].petrol = 6;
    p[2].petrol = 7;
    p[3].petrol = 4;

    //distance initialization
    p[0].distance = 6;
    p[1].distance = 5;
    p[2].distance = 3;
    p[3].distance = 5;

    cout<<"Petrol : ";
    for (int i = 0; i < 4; i++)
    {
        cout<<p[i].petrol<<" ";
    }
    cout<<endl;
    cout<<"Distance : ";
    for (int i = 0; i < 4; i++)
    {
        cout<<p[i].distance<<" ";
    }
    cout<<endl;
    cout<<"Starting point of Circular tour is : "<<Circulartour(p,4)<<endl;
    return 0;
}