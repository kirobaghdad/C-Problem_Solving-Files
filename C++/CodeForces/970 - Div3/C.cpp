#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> ans(n);
    int temp;
    int j, diff;

    int l, r;

    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        temp = 0;
        j = l;
        diff = 1;

        while (j <= r)
        {
            temp++;
            j += diff;
            diff++;
        }

        ans[i] = temp;
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;

    return 0;
}