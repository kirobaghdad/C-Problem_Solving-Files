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

    int n, q;
    long long x;
    long long ans;

    unordered_map<long long, int> m;
    vector<int> tempAns;
    vector<vector<int>> a = vector<vector<int>>(t);

    int prev = 0;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> q;
        m.clear();

        cin >> x;
        ans = n - 1;

        m.insert({ans, 1});

        for (int j = 1; j < n; j++)
        {
            prev = x;
            cin >> x;

            ans -= j < 2 ? 0 : j - 1;

            if (x - prev - 1)
                m[ans] += x - prev - 1;

            ans += n - j - 1;

            m[ans]++;
        }

        tempAns = vector<int>(q, 0);

        for (int j = 0; j < q; j++)
        {
            cin >> x;

            if (m.count(x) != 0)
                tempAns[j] = m[x];
        }

        a[i] = tempAns;
    }

    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j];

            if (j != a[i].size() - 1)
                cout << " ";
        }

        if (i != t - 1)
            cout << endl;
    }

    return 0;
}