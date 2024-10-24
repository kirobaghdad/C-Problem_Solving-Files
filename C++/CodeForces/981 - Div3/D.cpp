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

    int num = 0;

    set<int> m;

    vector<int> ans(t, 0);

    int sum;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        m.clear();

        sum = 0;

        for (int j = 0; j < n; j++)
        {
            cin >> num;

            if (num == 0)
            {
                ans[i]++;
                m.clear();
                sum = 0;
            }
            else
            {
                sum += num;

                if (m.count(sum) || sum == 0)
                {
                    ans[i]++;
                    m.clear();
                    sum = 0;
                }
                else
                    m.insert(sum);
            }
        }
    }

    for (int i = 0; i < t; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}