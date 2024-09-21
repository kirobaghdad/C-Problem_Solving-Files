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
    TreeNode *getNode(TreeNode *t)
    {
        t = t->right;

        while (t->left)
            t = t->left;

        return t;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if (!root)
            return nullptr;

        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else
        {
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;
            else
            {
                TreeNode *nodeToDelete = getNode(root);
                root->val = nodeToDelete->val;
                root->right = deleteNode(root->right, root->val);

                return root;
            }
        }
    }
};

int main()
{

    return 0;
}