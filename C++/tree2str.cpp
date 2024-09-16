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
    string tree2str(TreeNode *root)
    {
        if (!root)
            return "";

        string ans = "";

        ans += to_string(root->val);
        if (root->left || (!root->left && root->right))
            ans += '(' + tree2str(root->left) + ')';
        if (root->right)
            ans += '(' + tree2str(root->right) + ')';

        return ans;
    }
};

int main()
{
    Solution s;

    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3));
    // TreeNode *root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(4)), new TreeNode(3));

    cout << s.tree2str(root);

    return 0;
}