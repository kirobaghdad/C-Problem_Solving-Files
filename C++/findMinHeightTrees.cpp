#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    vector<TreeNode *> children;

    TreeNode(int data)
    {
        this->data = data;
    }

    void addChild(TreeNode *child)
    {
        children.push_back(child);
    }
};

class Solution
{
public:
    vector<bool> isVisited;
    int findHeight(TreeNode *root)
    {
        if (isVisited[root->data] == true)
            return 0;
        else
        {
            isVisited[root->data] = true;
            vector<int> heights = vector<int>(0);
            for (int i = 0; i < root->children.size(); i++)
            {
                heights.push_back(findHeight(root->children[i]));
            }

            // Find max(subtree_height) + 1 to get the height of the tree
            return heights.size() ? *max_element(heights.begin(), heights.end()) + 1 : 1;
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>> edges)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<TreeNode *> nodes;

        for (int i = 0; i < n; i++)
            nodes.push_back(new TreeNode(i));

        for (int i = 0; i < edges.size(); i++)
        {
            nodes[edges[i][0]]->addChild(nodes[edges[i][1]]);
            nodes[edges[i][1]]->addChild(nodes[edges[i][0]]);
        }

        vector<int> ans;

        int m = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            TreeNode *root = nodes[i];

            isVisited = vector<bool>(n, 0);
            int temp = findHeight(root) - 1;
            if (m > temp)
            {
                m = temp;
                ans.clear();
                ans.push_back(i);
            }
            else if (m == temp)
                ans.push_back(i);
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> ans = s.findMinHeightTrees(5, {});

    for (auto it : ans)
        cout << it << endl;

    return 0;
}