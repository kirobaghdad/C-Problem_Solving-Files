#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;

int main(int argc, char **argv)
{
    int t;
    cin >> t;
    bool *ans = new bool[t];
    int a, b, c;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b >> c;
        ans[i] = (((a + c) % (2 * b) == 0 && (a + c) / (2 * b) > 0)) || (((2 * b - c) % a) == 0 && ((2 * b - c) / a) > 0) || (((2 * b - a) % c) == 0 && ((2 * b - a) / c) > 0);
    }

    for (int i = 0; i < t; i++)
        if (ans[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    delete[] ans;
    return 0;
}