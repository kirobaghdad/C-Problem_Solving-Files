#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        queue<char> senators;
        int R = 0;
        int D = 0;

        for (int i = 0; i < senate.size(); i++)
        {
            if (senate[i] == 'D')
                D++;
            else
                R++;

            senators.push(senate[i]);
        }

        int banR = 0;
        int banD = 0;
        char temp;

        while (true)
        {
            temp = senators.front();
            senators.pop();

            if (temp == 'R')
            {
                if (banR == 0)
                {
                    senators.push(temp);
                    banD++;
                }
                else
                {
                    R--;
                    banR--;
                }
            }
            else
            {
                if (banD == 0)
                {
                    senators.push(temp);
                    banR++;
                }
                else
                {
                    D--;
                    banD--;
                }
            }

            if (D == 0)
                return "Radiant";
            if (R == 0)
                return "Dire";
        }
    }
};

int main()
{
    Solution s;

    cout << s.predictPartyVictory("DDRRR");

    return 0;
}