
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
        vector<int> ans;
        queue<TreeNode *> q;

        q.push(root);

        while (q.size())
        {
            int l = q.size();

            for (int i = 0; i < l; i++)
            {
                TreeNode *temp = q.front();
                q.pop();

                if (i == l - 1)
                    ans.push_back(temp->val);

                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), NULL), new TreeNode(3));

    vector<int> ans = s.rightSideView(root);

    for (auto &i : ans)
        cout << i << endl;

    return 0;
}