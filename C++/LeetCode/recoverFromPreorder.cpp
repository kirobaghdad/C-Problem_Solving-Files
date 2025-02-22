#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // construct the tree
    int i = 0;
    void solve(string &tr, TreeNode *ans, int l = 0)
    {
        if (tr.size() == i)
            return;

        // get number of -
        int j = i;
        int temp = 0;

        while (tr[j] == '-')
        {
            temp++;
            j++;
        }

        if (temp == l + 1)
        {
            // left
            i = j;
            while (i < tr.size() && tr[i] != '-')
                i++;

            ans->left = new TreeNode(stoi(tr.substr(j, i - j)));
            solve(tr, ans->left, l + 1);
        }

        j = i;
        temp = 0;

        while (tr[j] == '-')
        {
            temp++;
            j++;
        }

        if (temp == l + 1)
        {
            i = j;
            while (i < tr.size() && tr[i] != '-')
                i++;

            ans->right = new TreeNode(stoi(tr.substr(j, i - j)));
            solve(tr, ans->right, l + 1);
        }
    }

    TreeNode *recoverFromPreorder(string tr)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        while (i < tr.size() && tr[i] != '-')
            i++;

        TreeNode *ans = new TreeNode(stoi(tr.substr(0, i)));

        solve(tr, ans);
        return ans;
    }
};

int main()
{
    Solution s;

    TreeNode *ans = s.recoverFromPreorder("10-7--8");
    return 0;
}