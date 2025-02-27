#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans = 0;
    map<int, int> nums;

    void solve(vector<int> &arr, vector<int> &temp, int i = 0)
    {
        if (i == arr.size())
            return;

        if ((temp.size() < 2))
        {
            // include
            temp.push_back(arr[i]);
            solve(arr, temp, i + 1);
            temp.pop_back();

            // exclude
            solve(arr, temp, i + 1);
        }
        else if ((nums.find((temp[temp.size() - 1] + temp[temp.size() - 2])) != nums.end()))
        {
            temp.push_back(temp[temp.size() - 1] + temp[temp.size() - 2]);

            if (temp.size() > 2)
                ans = max(ans, (int)temp.size());

            solve(arr, temp, nums[(temp[temp.size() - 2] + temp[temp.size() - 3])] + 1);
            temp.pop_back();
        }
    }

    int lenLongestFibSubseq(vector<int> arr)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int> temp;
        for (int i = 0; i < arr.size(); i++)
            nums.insert({arr[i], i});
        solve(arr, temp);

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.lenLongestFibSubseq({1, 3, 4, 7, 10, 11, 12, 18, 23, 35});

    return 0;
}