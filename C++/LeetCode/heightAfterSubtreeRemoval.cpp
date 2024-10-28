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
    map<int, int> val2H, removal;
    int h(TreeNode *root)
    {
        if (!root)
            return -1;
        int x = root->val;
        if (val2H.count(x))
            return val2H[x];
        return val2H[x] = 1 + max(h(root->left), h(root->right));
    }

    void dfs(TreeNode *root, int level, int maxLevel)
    {
        if (!root)
            return;
        int x = root->val;
        removal[x] = maxLevel;
        dfs(root->left, level + 1, max(maxLevel, 1 + level + h(root->right)));
        dfs(root->right, level + 1, max(maxLevel, 1 + level + h(root->left)));
    }

    vector<int> treeQueries(TreeNode *root, vector<int> queries)
    {
        dfs(root, 0, 0);

        vector<int> ans(queries.size());
        int i = 0;
        for (int q : queries)
            ans[i++] = removal[q];
        return ans;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

int main()
{
    Solution s;

    s.treeQueries(new TreeNode(1, new TreeNode(3, new TreeNode(2), nullptr), new TreeNode(4, new TreeNode(6), new TreeNode(5, nullptr, new TreeNode(7)))), {4});

    return 0;
}