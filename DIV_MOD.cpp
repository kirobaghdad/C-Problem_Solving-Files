#include <iostream>
using namespace std;

int maxNum(int l, int r, int a)
{
    if (a == 1)
        return r;
    if (r % a == 0)
    {
        if (r != l)
            r -= 1;
    }
    else if (r > a)
    {
        if ((r / a) * a - 1 >= l && !((r + 1) % a == 0))
            r = (r / a) * a - 1;
    }
    return (r / a + r % a);
}
template <class T>
void printArray(T arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    int *ans = new int[t];
    int l, r, a;

    for (int i = 0; i < t; i++)
    {
        cin >> l >> r >> a;
        ans[i] = maxNum(l, r, a);
    }

    printArray(ans, t);
}