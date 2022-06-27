#include <iostream>
using namespace std;

template <class T>
void printArray(T arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int minNum(int n)
{
    if (n == 1)
        return 3;
    if (n % 2 == 1)
        return 1;
    else
    {
        if ((n & (n - 1)) == 0)
            return n + 1;
        else
        {
            return n & ~(n - 1);
        }
    }
    // int y = 1;
    // while (((n & y) == 0) || ((n ^ y) == 0))
    // {
    //     y++;
    // }
    // return y;
}

int main()
{
    int t;
    cin >> t;
    int *ans = new int[t];
    int n;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        ans[i] = minNum(n);
    }

    printArray(ans, t);
}