#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numRabbits(vector<int> &answ)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 0;

        map<int, int> m;

        for (int i = 0; i < answ.size(); i++)
        {
            if (m.find(answ[i]) == m.end())
                ans += answ[i] + 1;

            m[answ[i]]++;

            if (m[answ[i]] == answ[i] + 1)
                m.erase(answ[i]);
        }

        return ans;
    }
};

int main()
{

    return 0;
}