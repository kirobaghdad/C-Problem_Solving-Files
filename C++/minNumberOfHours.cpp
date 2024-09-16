#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> energy, vector<int> experience)
    {
        int ans = 0;
        int e = -initialEnergy + 1;

        for (int i = 0; i < energy.size(); i++)
        {
            e += energy[i];

            if (initialExperience <= experience[i])
            {
                ans += experience[i] - initialExperience + 1;
                initialExperience += experience[i] - initialExperience + 1;
            }
            initialExperience += experience[i];
        }

        if (e > 0)
            ans += e;

        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.minNumberOfHours(3, 2, {1}, {2});

    return 0;
}