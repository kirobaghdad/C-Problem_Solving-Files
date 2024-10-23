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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        vector<int> levelSum;

        queue<TreeNode *> s;
        s.push(root);

        int sum = 0;
        TreeNode *temp;

        while (s.size())
        {
            sum = 0;

            int j = s.size();

            while (j)
            {
                temp = s.front();
                sum += temp->val;

                if (temp->left)
                    s.push(temp->left);

                if (temp->right)
                    s.push(temp->right);

                j--;
                s.pop();
            }

            levelSum.push_back(sum);
        }

        levelSum.push_back(0);

        root->val = 0;

        s.push(root);

        int l = 0;

        while (s.size())
        {

            int j = s.size();

            while (j)
            {
                temp = s.front();
                sum = levelSum[l + 1];

                if (temp->left)
                {
                    sum -= temp->left->val;
                    s.push(temp->left);
                }

                if (temp->right)
                {
                    sum -= temp->right->val;
                    s.push(temp->right);
                }

                if (temp->right)
                    temp->right->val = sum;

                if (temp->left)
                    temp->left->val = sum;

                j--;

                s.pop();
            }

            l++;
        }

        return root;
    }
};

int main()
{

    return 0;
}