#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> arr)
    {
        int MOD = 1000000007;
        sort(arr.begin(), arr.end()); // Sort the array.

        unordered_map<int, long long> dp; // Use a map to store the number of trees for each value.

        for (int i = 0; i < arr.size(); i++)
        {
            dp[arr[i]] = 1; // A single node tree with the value arr[i].
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0)
                { // If arr[j] is a factor of arr[i].
                    int factor = arr[i] / arr[j];
                    if (dp.count(factor))
                    {
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[factor]) % MOD;
                    }
                }
            }
        }

        long long result = 0;
        for (auto &entry : dp)
        {
            result = (result + entry.second) % MOD;
        }

        return static_cast<int>(result);
    }
};

// class Solution
// {
// public:
//     int numFactoredBinaryTrees(vector<int> arr)
//     {
//         vector<int> dp_prev(arr.size(), 1);
//         vector<int> dp_current(arr.size(), 0);

//         sort(arr.begin(), arr.end());

//         int ans = arr.size();

//         for (int n = 3; n <= pow(2, log2(arr.size() + 1)) - 1; n++)
//         {
//             for (int i = 0; i < arr.size(); i++)
//             {
//                 // Parent Loop
//                 for (int j = i - 1; j < arr.size(); j++)
//                 {
//                     for (int k = j; k < arr.size(); k++)
//                     {
//                         if (arr[j] * arr[k] == arr[i])
//                         {
//                             if (j == k)
//                             {
//                                 dp_current[i] += dp_prev[j];
//                                 ans += dp_current[i];
//                             }
//                             else
//                             {
//                                 dp_current[i] += 2 * (dp_prev[j] * dp_prev[k]);
//                                 ans += dp_current[i];
//                             }
//                         }
//                         else if (arr[j] * arr[k] > arr[i])
//                             break;
//                     }
//                 }
//             }

//             dp_prev = dp_current;
//             dp_current = vector<int>(arr.size(), 0);
//         }
//     }
// };

int main()
{
    Solution s;
    cout << s.numFactoredBinaryTrees({2, 4, 5, 10});

    return 0;
}