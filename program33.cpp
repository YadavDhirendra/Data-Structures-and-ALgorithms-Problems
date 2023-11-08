/*Problem : Given an array 'arr' of integers , where 'arr[i]' represents the number of pages in the 'i-th' book. There are 'm' number of students and the task is to allocate all the books to their students. Allocate books in such a way that :
1. Each student gets at least one book.
2. Each book should be allocated to a student.
3. Book allocation should be in a contiguous manner.
You have to allocate the book to 'm' students such that the maximum no. of pages assigned to a student is minimum. */
#include <iostream>
using namespace std;

bool possible(int a[], int n, int m, int mid)
{
    int studentcount = 1;
    int pagesum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesum + a[i] <= mid)
        {
            pagesum += a[i];
        }
        else
        {
            studentcount++;
            if (studentcount > m || a[i] > mid)
                return false;
            pagesum = a[i];
        }
    }
    return true;
}
int bookallocate(int a[], int n, int m)
{
    int s = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    int e = sum, ans = 0;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (possible(a, n, m, mid))
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
    int a[100], size, stud, sum = 0;
    cout << "Enter the no. of books :\n";
    cin >> size;
    cout << "Enter the pages of books :\n";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    cout << "Enter the no. of students :\n";
    cin >> stud;
    int book = bookallocate(a, size, stud);
    cout << "The maximium no. of pages assigned to a student is " << book;
    return 0;
}