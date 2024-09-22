#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    int n, k;
    int s;

    vector<bool> ans(t, false);

    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        s = 0;

        for (int j = n; j > n - k; j--)
            s += pow(j, j);

        ans[i] = s % 2 == 0;
    }

    for (int i = 0; i < t; i++)
        cout << (ans[i] ? "YES" : "NO") << endl;

    return 0;
}