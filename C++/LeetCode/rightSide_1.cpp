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
    vector<int> rightSideView(TreeNode *root)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> ans;

        if (!root)
            return ans;

        // consider the depth

        stack<pair<TreeNode *, int>> s;
        s.push({root, 1});

        int lastDep = 0;

        TreeNode *temp;
        int dep;

        while (!s.empty())
        {
            temp = s.top().first;
            dep = s.top().second;

            if (dep > lastDep)
            {
                lastDep = s.top().second;
                ans.push_back(temp->val);
            }

            s.pop();

            if (temp->left)
                s.push({temp->left, dep + 1});

            if (temp->right)
                s.push({temp->right, dep + 1});
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    vector<int> ans = solution.rightSideView(new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3, nullptr, new TreeNode(4))));

    for (auto it : ans)
        cout << it << endl;

    return 0;
}