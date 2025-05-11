#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if (arr.size() >= 3)
            for (int i = 0; i <= arr.size() - 3; i++)
            {
                if (arr[i] % 2 == 1 && arr[i + 1] % 2 == 1 && arr[i + 2] % 2 == 1)
                    return true;
            }

        return false;
    }
};
int main()
{

    return 0;
}