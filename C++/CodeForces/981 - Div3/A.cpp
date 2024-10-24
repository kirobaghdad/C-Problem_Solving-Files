#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 0;

    cin >> t;

    vector<bool> ans(t, 0);

    int n;

    int temp = 0;
    bool tu = 0;
    int turn;

    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        tu = 0;
        turn = 1;
        temp = 0;
        // Sakurako

        while (abs(temp) <= n)
        {
            if (!tu)
            {
                temp -= (2 * turn - 1);
            }
            else
                temp += (2 * turn - 1);

            turn++;
            tu = !tu;
        }

        ans[i] = !tu;
    }

    for (int i = 0; i < t; i++)
    {
        if (!ans[i])
            cout << "Sakurako" << endl;
        else
            cout << "Kosuke" << endl;
    }

    return 0;
}