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
    int ans = 0;

    void solve(TreeNode *root, int num = 0)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        if (!root)
            return;

        if (!root->left && !root->right)
        {
            ans += stoi(to_string(num) + to_string(root->val));
            // nums.push_back(stoi(to_string(num) + to_string(root->val)));
            return;
        }

        solve(root->left, stoi(to_string(num) + to_string(root->val)));
        solve(root->right, stoi(to_string(num) + to_string(root->val)));
    }

    int sumNumbers(TreeNode *root)
    {
        solve(root);
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.sumNumbers(new TreeNode(1, new TreeNode(2), new TreeNode(3)));
    // cout << s.sumNumbers(new TreeNode(4, new TreeNode(9, new TreeNode(5), new TreeNode(1)), new TreeNode(0)));

    return 0;
}