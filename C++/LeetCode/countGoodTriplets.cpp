#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int ans = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (abs(arr[i] - arr[j]) <= a)
                    for (int k = j + 1; k < arr.size(); k++)
                    {
                        if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                            ans++;
                    }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}