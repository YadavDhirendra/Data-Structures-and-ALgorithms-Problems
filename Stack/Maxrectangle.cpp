//Max rectangle
//Given a biary matrix M of size nXm .Find the max area of a rectangle formed only of 1s in the given matrix
//Step involes : 1.Compute max-area for 1st row
//2.For every remaining row add upper row elements and then find max area
#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> arr)
{
    vector<int> ans = arr;
    int n = arr.size();
    stack<int> s;
    s.push(-1);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> nextSmaller(vector<int> arr)
{
    vector<int> ans = arr;
    int n = arr.size();
    stack<int> s;
    s.push(-1);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRecHistogram(vector<int> heights)
{
    int n = heights.size();
    //next smaller elements'index array
    vector<int> next = nextSmaller(heights);

    //prev smalller elements'index array
    vector<int> prev = prevSmaller(heights);

    int area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
            next[i] = n;

        int b = next[i] - prev[i] - 1;

        int newarea = l * b;
        area = max(area, newarea);
    }
    return area;
}

int maxarea(vector<vector<int>> M, int n, int m)
{   
    //step 1.Find max area for first row
    int area = largestRecHistogram(M[0]);

    //step 2.For every remaining row add upper row elements and then find max area
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {   
            //if M[i][j] is 0 then no need to add upper row elements as it can't contribute in area 
            if(M[i][j]!=0)
            M[i][j] = M[i][j] + M[i-1][j];
            else
            M[i][j] = 0;
        }
        int newarea = largestRecHistogram(M[i]);
        area = max(area,newarea);
    }
    return area;
}       

int main()
{
    vector<vector<int>> M = {{0, 1, 1, 0},
                             {1, 1, 1, 1},
                             {1, 1, 1, 1},
                             {1, 1, 0, 0}};
    int n = 4, m = 4;
    cout<<"The largest area of given array is : "<<maxarea(M,n,m)<<endl;
    return 0;
}