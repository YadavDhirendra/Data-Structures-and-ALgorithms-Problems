#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    char str[100];
    cout << "enter the operation :\n";
    cin >> str;
    int i = 0, a = 0, b = 0, temp = 0;
    char c;
    if (str[i] == '-')
    {
        temp = 1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') //for getting first integer
    {
        a = a * 10 + (str[i] - '0');
        i++;
    }
    if (temp == 1)
    {
        a = -a;
    }
    temp = 0;

    c = str[i]; //for getting the operator
    i++;
    if (str[i] == '-')
    {
        temp = 1;
        i++;
    }

    while (str[i] != '\0') //for getting second integer
    {
        b = b * 10 + (str[i] - '0');
        i++;
    }
    if (temp == 1)
    {
        b = -b;
    }

    switch (c)
    {
    case '*':
        cout << "The product of " << a << " and " << b << " is " << a * b;
        break;
    case '/':
        cout << "The division of " << a << " and " << b << " is " << a / b;
        break;
    case '+':
        cout << "The addition of " << a << " and " << b << " is " << a + b;
        break;
    case '-':
        cout << "The subtraction of " << a << " and " << b << " is " << a - b;
        break;

    default:
        break;
    }

    return 0;
}