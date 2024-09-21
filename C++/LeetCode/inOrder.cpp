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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> nums;

        if (!root)
            return nums;

        vector<int> temp = inorderTraversal(root->left);
        nums.insert(nums.end(), temp.begin(), temp.end());
        nums.push_back(root->val);
        temp = inorderTraversal(root->right);
        nums.insert(nums.end(), temp.begin(), temp.end());

        return nums;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));

    Solution s;
    vector<int> ans = s.inorderTraversal(root);

    for (auto i : ans)
        cout << i << " ";
    return 0;
}