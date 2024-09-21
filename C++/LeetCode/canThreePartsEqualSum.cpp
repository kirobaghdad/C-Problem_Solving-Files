#include <iostream>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> arr)
    {
        bool ans = false;

        int sumLeft = arr[0];
        int sumRight = arr[arr.size() - 1];

        int i = 0;
        int j = arr.size() - 1;

        while (j > i)
        {
            if (sumLeft < sumRight)
            {
                i++;
                sumLeft += arr[i];
            }
            else if (sumLeft > sumRight)
            {
                j--;

                while (j > i && sumLeft > sumRight)
                {
                    sumRight += arr[j];
                    j--;
                }
            }
            else
            {
                // cout << accumulate(arr.begin() + i + 1, arr.begin() + j + 1, 0);
                if (sumLeft == accumulate(arr.begin() + i + 1, arr.begin() + j + 1, 0))
                {
                    ans = true;
                    break;
                }
                else
                {
                    i++;
                    j--;
                    sumLeft += arr[i];
                    sumRight += arr[j];
                }
            }
        }

        return ans;
    }
};

int main()
{

    Solution s;
    cout << s.canThreePartsEqualSum({18, 12, -18, 18, -19, -1, 10, 10});

    return 0;
}