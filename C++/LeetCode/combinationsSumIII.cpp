#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;

    void solve(int k, int n, vector<int> temp, int c = 0, int s = 0)
    {

        if (c < k - 1)
        {
            int t = (temp.size() ? temp[temp.size() - 1] : 0) + 1;
            while (n - (s + t) > t)
            {
                temp.push_back(t);
                solve(k, n, temp, c + 1, s + t);
                temp.erase(temp.begin() + temp.size() - 1);
                t++;
            }
        }
        else
        {
            temp.push_back(n - s);
            ans.push_back(temp);
        }
    }

    // backtracking
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<int> t;
        solve(k, n, t);

        return ans;
    }
};

int main()
{

    Solution s;

    s.combinationSum3(3, 9);

    return 0;
}

/*
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> v;
        v.push_back(1);
        int sum = 1;
        int temp;

        bool found = false;

        vector<vector<int>> ans;

        while (true)
        {
            while (v.size() < k - 1)
            {
                temp = v[v.size() - 1];
                temp++;
                sum += temp;
                v.push_back(temp);
            }

            if (n - sum > v[v.size() - 1])
            {
                found = true;
                v.push_back(n - sum);
                ans.push_back(v);
                v.erase(v.begin() + v.size() - 1);
                temp = v[v.size() - 1] + 1;
                v.erase(v.begin() + v.size() - 1);
                v.push_back(temp);
                sum += 1;
            }
            else
            {
                if ()
                    break;
                sum -= v[v.size() - 1];
                v.erase(v.begin() + v.size() - 1);
                temp = v[v.size() - 1] + 1;
                v.erase(v.begin() + v.size() - 1);
                v.push_back(temp);
                sum += 1;
            }
        }

        return ans;
        */