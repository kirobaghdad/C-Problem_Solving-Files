#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int curr = 0;
        int ans = 0;

        for (int i = 0; i < key.length(); i++)
        {
            if (ring[curr] == key[i])
            {
                ans++;
                continue;
            }
            else
            {
                int temp = (curr + 1) % ring.length();

                int tempAns = INT_MAX;
                int ansPos = -1;

                while (temp % ring.size() != curr)
                {
                    if (ring[temp] == key[i])
                    {

                        if (abs(temp - curr) + 1 < tempAns)
                        {
                            ansPos = temp;
                            tempAns = abs(temp - curr) + 1;
                        }

                        // int first = min(temp, curr);
                        // int last = max(temp, curr);

                        // if ((ring.length() - first) + (ring.size() - last - 1) + 1 < tempAns)
                        // {
                        //     ansPos = temp;
                        //     tempAns = (ring.length() - first) + (ring.size() - last - 1) + 1;
                        // }

                        int begin = min(curr, temp);
                        int last = max(curr, temp);

                        int count = 0;

                        while (last != begin)
                        {
                            last++;
                            if (last == ring.length())
                                last = 0;

                            count++;
                        }
                        count++;

                        if (count < tempAns)
                        {
                            ansPos = temp;
                            tempAns = count;
                        }
                    }

                    temp++;
                    temp = temp % ring.length();
                }

                ans += tempAns;
                curr = ansPos;
            }
        }

        return ans;
    }
};

int main()
{

    Solution s;

    cout << s.findRotateSteps("edcba", "abcde");

    return 0;
}