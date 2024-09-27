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

    int n;

    vector<int> ans(t, 0);

    int m, ind;
    int num;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        m = -1;

        for (int j = 0; j < n; j++)
        {
            cin >> num;

            if (num > m)
            {
                m = num;
                ind = j;
            }
            else if (num == m)
            {
                if (ind % 2 == 1)
                    ind = j;
            }
        }

        ans[i] = m + (n % 2 == 0 ? n / 2 : (ind % 2 == 0 ? (n / 2) + 1 : n / 2));
    }

    for (auto i : ans)
        cout << i << endl;

    return 0;
}