#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string pushDominoes(string domi)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        map<int, int> next;

        int prev = -1;

        for (int i = 0; i < domi.size(); i++)
        {
            if (domi[i] != '.')
            {
                if (prev != -1)
                {
                    next[prev] = i;
                }

                prev = i;
            }
        }

        for (int i = 0; i < domi.size(); i++)
        {
            if (domi[i] != '.')
            {
                if (domi[i] == 'L')
                {
                    int j = i - 1;
                    while (j >= 0 && domi[j] == '.')
                        domi[j--] = 'L';
                }
                else
                {
                    if (next.find(i) != next.end())
                        if (domi[next[i]] == 'L')
                        {
                            int s = next[i] - i + 1;
                            // in the middle
                            int j = i + 1;
                            while (j < i + s / 2)
                                domi[j++] = 'R';

                            if (s % 2)
                                j++;

                            while (j < next[i])
                                domi[j++] = 'L';

                            i = j;
                        }
                        else
                        {
                            int s = next[i] - i + 1;
                            int j = i + s;
                            i++;
                            while (i < j && domi[i] == '.')
                                domi[i++] = 'R';

                            i--;
                        }
                    else
                        while (i < domi.size())
                            domi[i++] = 'R';
                }
            }
        }

        return domi;
    }
};

int main()
{
    Solution s;

    cout << s.pushDominoes("RR.L");

    return 0;
}