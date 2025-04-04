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
class Solution {
public:
    int mx = -1;
    TreeNode* ans = nullptr;

    int solve(TreeNode* root, int depth = 0)
    {
        if(root && !root->left && !root->right)
        {
            if(depth > mx)
            {
                mx = depth;
                ans = root;   
            }

            return depth;
        }


        if(!root)
            return 0;

        int a = solve(root->left, depth + 1);
        int b = solve(root->right, depth + 1);

        if(a == b && a >= mx)
        {
            mx = a;
            ans = root;
        }

        return max(a, b);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        solve(root);
        
        return ans;
    }
};
