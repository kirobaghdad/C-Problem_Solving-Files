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
    void solve(TreeNode *root, int val, int depth)
    {
        if (!root)
            return;

        if (depth == 2)
        {
            root->left = new TreeNode(val, root->left, nullptr);
            root->right = new TreeNode(val, nullptr, root->right);
            return;
        }

        solve(root->left, val, depth - 1);
        solve(root->right, val, depth - 1);
    }

    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if (depth == 1)
            root = new TreeNode(val, root, nullptr);
        else
            solve(root, val, depth);
        return root;
    }
};

int main()
{
    TreeNode *root = new TreeNode(4, new TreeNode(2, new TreeNode(3), new TreeNode(1)), new TreeNode(6, new TreeNode(5), nullptr));

    Solution s;

    root = s.addOneRow(root, 1, 2);

    cout << "Test";

    return 0;
}