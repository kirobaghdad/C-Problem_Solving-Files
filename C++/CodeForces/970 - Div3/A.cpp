#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int a, b, c;

    vector<bool> ans(n, false);

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cin >> b;

        b = b * 2;

        if ((a + b) % 2 == 0)
        {
            c = (a + b) / 2;

            b = b / 2;

            c -= min(b, c / 2) * 2;

            if (a >= c)
                ans[i] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[i])
            cout << "YES";
        else
            cout << "NO";

        cout << endl;
    }
}