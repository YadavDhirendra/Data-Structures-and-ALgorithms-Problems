//Largest Rectangle in histogram by brute force
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

    for (int i = n-1; i >=0 ; i--)
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
    //next smaller elements array
    vector<int> next = nextSmaller(heights);
    //previous smaller elements array
    vector<int> prev = prevSmaller(heights);

    int area = INT_MIN;
    for (int i = 0; i < heights.size(); i++)
    {
        int l = heights[i];

        if (next[i] == -1)
            next[i] = n;

        int b = next[i] - prev[i] - 1;
        int newarea = l*b;
        area = max(area,newarea);
    }
    return area;
}

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout<<"Largest area of rectangle in given histogram is : "<<largestRecHistogram(heights)<<endl;
    return 0;
}