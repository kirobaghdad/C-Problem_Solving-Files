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

    int n, x;

    vector<int> nums;
    vector<int> ans(t, -1);
    map<int, int> repeated;

    int temp;

    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cin >> x;

        temp = 0;

        nums = vector<int>(n);
        repeated.clear();

        for (int j = 0; j < n; j++)
            cin >> nums[j];

        sort(nums.begin(), nums.end());

        for (int j = 0; j < n; j++)
        {
            if (nums[j] == temp)
                temp = nums[j] + 1;
            else if (nums[j] < temp)
            {
                repeated[nums[j]]++;
            }
            else
            {
                ans[i] = temp;
                break;
            }
        }

        if (ans[i] == -1)
        {
            bool opt = 0;

            while (true)
            {
                opt = 0;

                for (auto it : repeated)
                {
                    if ((temp - it.first) % x == 0)
                    {
                        temp++;
                        it.second--;
                        opt = 1;
                    }

                    if (it.second == 0)
                        repeated.erase(it.first);
                }

                if (!opt)
                    break;
                ans[i] = temp;
            }
        }
    }

    for (int i = 0; i < t; i++)
        cout << ans[i] << endl;

    return 0;
}