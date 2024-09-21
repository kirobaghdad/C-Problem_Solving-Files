#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    string s;
    int l;
    int sq;

    cin >> n;
    vector<bool> ans(n, false);
    bool x;

    for (int i = 0; i < n; i++)
    {
        cin >> l;
        cin >> s;

        sq = sqrt(l);

        if (sq * sq == l)
        {
            x = false;
            for (int r = 1; r < sq - 1; r++)
            {
                if (x)
                    break;

                for (int j = r * sq + 1; j <= r * sq + sq - 2; j++)
                    if (s[j] == '1')
                    {
                        x = true;
                        break;
                    }
            }

            if (!x)
                ans[i] = true;
        }
    }

    for (auto it : ans)
        if (it)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    return 0;
}