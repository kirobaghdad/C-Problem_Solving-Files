#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Wrong Solution

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;

    cin >> t;

    map<int, int> m, mInv;

    int n;

    int temp;

    vector<int> ans(t);

    for (int i = 0; i < t; i++)
    {
        m.clear();
        mInv.clear();

        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> temp;

            m.insert({temp, j + 1});
            mInv.insert({j + 1, temp});
        }

        for (auto it : m)
        {
            if (it.first != m[it.second])
            {
                ans[i]++;

                int s = m[it.second]; // 3

                m[it.second] = it.first; // 2

                m[mInv[it.first]] = s;
            }
        }
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;

    return 0;
}