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
    vector<int> ans(t, 0);

    int n, k;
    int g;
    int curr = 0;

    for (int i = 0; i < t; i++)
    {
        curr = 0;
        cin >> n >> k;

        for (int j = 0; j < n; j++)
        {
            cin >> g;
            if (g >= k)
                curr += g;
            else if (g == 0)
            {
                if (curr)
                {
                    ans[i]++;
                    curr--;
                }
            }
        }
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;
    return 0;
}