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
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        queue<TreeNode *> q;
        q.push(root);

        TreeNode *temp;

        vector<int> sums;

        while (q.size())
        {
            // Level
            int s = q.size();

            int t = 0;

            for (int j = 0; j < s; j++)
            {
                temp = q.front();
                t += temp->val;

                if (temp->left)
                {
                    q.push(temp->left);
                }

                if (temp->right)
                {
                    q.push(temp->right);
                }
                q.pop();
            }

            sums.push_back(t);
        }

        sort(sums.begin(), sums.end());

        return k > sums.size() ? -1 : sums[sums.size() - k];
    }
};

int main()
{

    Solution s;

    cout << s.kthLargestLevelSum(new TreeNode(5, new TreeNode(8, new TreeNode(2, new TreeNode(4), new TreeNode(6)), new TreeNode(1)), new TreeNode(9, new TreeNode(3), new TreeNode(7))), 2);
    return 0;
}