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

    int temp;

    vector<vector<int>> nums;

    for (int i = 0; i < t; i++)
    {
        cin >> n;

        nums = vector<vector<int>>(n, vector<int>(n));

        for (int j = 0; j < nums[0].size(); j++)
        {
            for (int k = 0; k < nums[0].size(); k++)
            {
                cin >> nums[j][k];
            }
        }

        temp = 0;

        int h;

        int count;

        count = nums.size();

        for (int j = 0; j < nums.size(); j++)
        {
            temp = 0;
            h = j;
            for (int k = 0; k < count; k++)
            {
                if (nums[k][h] < 0 && abs(nums[k][h]) > temp)
                    temp = abs(nums[k][h]);

                h++;
            }

            count--;

            ans[i] += temp;
        }

        count = nums.size() - 1;

        for (int j = 1; j < nums.size(); j++)
        {
            temp = 0;
            h = j;

            for (int k = 0; k < count; k++)
            {
                if (nums[h][k] < 0 && abs(nums[h][k]) > temp)
                    temp = abs(nums[h][k]);

                h++;
            }

            count--;

            ans[i] += temp;
        }
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;

    return 0;
}