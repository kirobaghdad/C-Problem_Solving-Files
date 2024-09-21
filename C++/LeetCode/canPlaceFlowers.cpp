#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> flowerbed, int n)
    {

        if (n == 0)
            return 1;

        if (flowerbed.size() == 1)
            return flowerbed[0] == 0 || n == 0;

        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0)
            {
                if (i == 0)
                {
                    if (i + 1 < flowerbed.size() && flowerbed[i + 1] == 0)
                    {
                        n--;
                        flowerbed[i] = 1;
                    }
                }
                else if (i == flowerbed.size() - 1)
                {
                    if (i - 1 >= 0 && flowerbed[i - 1] == 0)
                    {
                        n--;
                        flowerbed[i] = 1;
                    }
                }
                else if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {
                    n = n - 1;
                    flowerbed[i] = 1;
                }
            }
        }

        return n <= 0;
    }
};

int main()
{
    Solution s;
    cout << s.canPlaceFlowers({0, 1, 0}, 1);

    return 0;
}