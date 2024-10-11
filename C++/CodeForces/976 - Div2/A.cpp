#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int loga_to_baseb(int a, int b)
{
    return log2(a) / log2(b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    int n, k;

    vector<int> ans(t, 0);
    int temp0, temp1, temp2;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        temp0 = 0;

        while (n != 0)
        {
            temp2 = pow(k, loga_to_baseb(n, k));
            temp1 = n / temp2;
            temp0 += temp1;
            n = n - temp1 * temp2;
        }

        ans[i] = temp0;
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;

    return 0;
}