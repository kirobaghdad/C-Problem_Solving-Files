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
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (!root)
            return nullptr;

        if (!root->left && !root->right)
        {
            if (target == root->val)
            {
                // delete root;
                return nullptr;
            }
            else
                return root;
        }

        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        if (!root->left && !root->right)
        {
            if (target == root->val)
            {
                // delete root;
                return nullptr;
            }
            else
                return root;
        }

        return root;
    }
};

int main()
{
    // TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(2), nullptr), new TreeNode(3, new TreeNode(2), new TreeNode(4)));
    TreeNode *root = new TreeNode(1, new TreeNode(1, new TreeNode(1), nullptr), nullptr);

    Solution s;

    s.removeLeafNodes(root, 1);

    return 0;
}