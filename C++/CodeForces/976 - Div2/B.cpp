#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    long long k;
    cin >> t;

    while (t--)
    {
        cin >> k;

        cout << k + int(sqrtl(k) + 0.5) << endl;
    }

    return 0;
}