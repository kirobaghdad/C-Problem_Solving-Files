#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class Solution
{
public:
    bool getNodePath(TreeNode *root, TreeNode *p, stack<TreeNode *> &path)
    {
        if (!root)
        {
            return false;
        }

        path.push(root);

        if (root->val == p->val)
            return true;

        bool a = getNodePath(root->left, p, path);

        if (a)
            return true;

        a = getNodePath(root->right, p, path);

        if (a)
            return true;
        else
        {
            path.pop();
            return false;
        }
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        stack<TreeNode *> path0, path1;
        TreeNode *temp = root;

        getNodePath(temp, p, path0);

        getNodePath(root, q, path1);

        set<TreeNode *> a, b, result;

        while (path0.size())
        {
            a.insert(path0.top());
            path0.pop();
        }

        while (path1.size())
        {
            b.insert(path1.top());
            path1.pop();
        }

        set_intersection(a.begin(), a.end(), b.begin(),
                         b.end(),
                         inserter(result, result.begin()));

        return *result.rbegin();
    }
};

int main()
{
    Solution s;

    TreeNode *p = new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4)));
    TreeNode *q = new TreeNode(1, new TreeNode(0), new TreeNode(8));

    TreeNode *head = new TreeNode(3, p, q);

    cout << s.lowestCommonAncestor(head, p, q)->val << endl;

    return 0;
}
