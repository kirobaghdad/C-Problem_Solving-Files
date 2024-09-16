#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int i = 0;
        int j = 0;
        int prevI = 0;
        int prevJ = 0;

        while (i < version1.size() || j < version2.size())
        {
            while (i < version1.size() && version1[i] != '.')
                i++;

            while (j < version2.size() && version2[j] != '.')
                j++;

            int t1 = prevI == i ? 0 : stoi(version1.substr(prevI, i - prevI));
            int t2 = prevJ == j ? 0 : stoi(version2.substr(prevJ, j - prevJ));

            if (t1 > t2)
                return 1;
            else if (t1 < t2)
                return -1;

            prevI = ++i;
            prevJ = ++j;
        }

        return 0;
    }
};

int main()
{
    Solution s;

    cout << s.compareVersion("0.1", "1.1");
    return 0;
}