#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long coloredCells(int n)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return 1 + 4 * ((n * (long long)(n + 1)) / 2 - n);
    }
};

int main()
{

    return 0;
}