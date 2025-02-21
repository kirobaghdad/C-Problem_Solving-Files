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

class FindElements
{
    TreeNode *t;

    void solve(TreeNode *root, bool dir, int pValue)
    {
        if (!root)
            return;

        if (dir == 0)
        {
            // left
            root->val = 2 * pValue + 1;
        }
        else
        {
            root->val = 2 * pValue + 2;
        }

        solve(root->left, 0, root->val);
        solve(root->right, 1, root->val);
    }

public:
    FindElements(TreeNode *root)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        t = root;
        t->val = 0;

        solve(t->left, 0, 0);
        solve(t->right, 1, 0);
    }

    bool myFind(TreeNode *node, int &target)
    {
        if (!node)
            return false;

        if (node->val == target)
            return true;

        return myFind(node->left, target) | myFind(node->right, target);
    }

    bool find(int target)
    {

        return myFind(t, target);
    }
};

int main()
{
    FindElements *obj = new FindElements(new TreeNode(-1, nullptr, new TreeNode(-1)));

    bool param_1 = obj->find(1);

    return 0;
}