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

// naming var in ps
int main()
{
    int t;
    cin >> t;
    int n;
    bool **arr = new bool *[t];
    string *str;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        arr[i] = new bool[n]{0};
        str = new string[n];
        for (int j = 0; j < n; j++)
        {
            cin >> str[j];
        }

        sort(str, str + n);

        for (int j = 0; j < )
    }
}