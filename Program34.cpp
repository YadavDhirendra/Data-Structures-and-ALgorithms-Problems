//Problem : You are given an array list of  length 'n' , where the arraylist represents the boards and each element of the given array list represents the length of each board.Some 'K' numbers of painters are available to point these boards. COnsider that each unit of a board takes 1 unit of time to paint.
//you are supposed to return the area of the minimum time to get this job done of painting all the 'N' boards under a constraint that any painter will only paint the continuous sections of boards.
#include <iostream>
using namespace std;

bool ispossible(int a[],int n, int k,int mid)
{
    int paintercount=1;
    int boardlength=0;
    for (int i = 0; i < n; i++)
    {
        if(boardlength + a[i]<=mid)
        {
            boardlength += a[i];
        }

        else
        {
            paintercount++;
            if(paintercount>k || a[i]>mid)
            return false;
        boardlength=a[i];
        }
    }
    
}
int painterpartition(int a[], int n, int k)
{
    int s = 0, totalboardlength = 0;
    for (int i = 0; i < n; i++)
    {
        totalboardlength += a[i];
    }
    int e = totalboardlength, ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (ispossible(a, n, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}
int main()
{
    int a[100], n, k;
    cout << "ENter the size of array ::\n";
    cin >> n;
    cout << "ENter the no. of painters :\n";
    cin >> k;
    cout << "Enter the length of each board in array ::\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans=painterpartition(a,n,k);
    cout<<"The maximum length of board allocated to a painter is "<<ans;
    return 0;
}