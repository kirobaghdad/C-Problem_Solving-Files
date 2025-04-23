#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countLargestGroup(int n)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        map<int, int> m;

        int size = 0;
        int ans = 0, temp = 0;
        string str;

        for (int i = 1; i <= n; i++)
        {
            temp = 0;
            int j = i;
            while (j)
            {
                temp += j % 10;
                j = j / 10;
            }

            m[temp]++;

            if (m[temp] > size)
            {
                size = m[temp];
                ans = 1;
            }
            else if (m[temp] == size)
            {
                ans++;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}