#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getNextI(const vector<int> &values, int i, int prev)
    {
        int j = i;

        while (j < values.size() && prev > values[j] + j)
            j++;

        return j;
    }

    int getNextJ(const vector<int> &values, int i, int prev)
    {
        int j = i;

        while (j < values.size() && prev > values[j] - j)
            j++;

        return j;
    }

    int maxScoreSightseeingPair(vector<int> values)
    {
        int i = 0;
        int j = 1;

        int ans = values[i] + values[j] + i - j;

        for (int k = 2; k < values.size(); k++)
        {
            if (values[k] - k > values[j] - j)
            {
                j = k;

                if (values[j - 1] + j - 1 > values[i] + i)
                {
                    i = j - 1;
                }

                ans = max(ans, values[i] + values[j] + i - j);
            }
            else
            {
                j++;
                if (values[j - 1] + j - 1 > values[i] + i)
                {
                    i = j - 1;
                }

                k = j;

                if (j < values.size())
                    ans = max(ans, values[i] + values[j] + i - j);
            }
        }

        // while (getNextI(values, i + 1, values[i] + i) < values.size() && getNextJ(values, j + 1, values[j] - i) < values.size())
        // {
        //     j = getNextJ(values, j + 1, values[j] - i);

        //     if (i < j)
        //         ans = max(ans, values[i] + values[j] + i - j);

        //     i = getNextI(values, i + 1, values[i] + i);
        // }

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.maxScoreSightseeingPair({10, 4, 6, 4, 10});

    return 0;
}