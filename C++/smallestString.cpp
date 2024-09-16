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
    string ans = "";

    // string getSmaller(string &s1, string &s2)
    // {
    //     string &shorter = s1.size() > s2.size() ? s2 : s1;
    //     string &longer = s1.size() > s2.size() ? s1 : s2;

    //     int i = 0;

    //     while (i < shorter.size() && shorter[i] == longer[i])
    //     {
    //         i++;
    //     }

    //     if (i == shorter.size())
    //     {
    //         if (shorter == "")
    //             return longer;
    //         else
    //             return shorter;
    //     }

    //     return shorter[i] > longer[i] ? longer : shorter;

    //     // for(int i = 0; i < shorter.size(); i++)
    //     // {
    //     //     if(shorter[i] )
    //     // }
    // }

    void solve(TreeNode *root, string curr = "")
    {
        if (!root)
            return;

        curr = (char)(root->val + 'a') + curr;

        if (!root->left && !root->right)
        {
            if (ans > curr || ans == "")
                ans = curr;

            return;
        }

        solve(root->left, curr);
        solve(root->right, curr);
    }

    string smallestFromLeaf(TreeNode *root)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        solve(root);
        return ans;
    }
};

int main()
{
    Solution s;
    // cout << s.smallestFromLeaf(new TreeNode(0));
    // cout << s.smallestFromLeaf(new TreeNode(4, new TreeNode(0, new TreeNode(1), nullptr), new TreeNode(1)));

    cout << s.smallestFromLeaf(new TreeNode(0, new TreeNode(1, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(3), new TreeNode(4))));

    return 0;
}