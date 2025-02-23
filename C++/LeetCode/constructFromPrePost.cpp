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
	TreeNode *constructFromPrePost(vector<int> preorder, vector<int> postorder)
	{
		stack<TreeNode *> nodes;
		TreeNode *root = new TreeNode(preorder[0]);
		nodes.push(root);

		int preIndex = 1, postIndex = 0;
		TreeNode *current;

		while (!nodes.empty())
		{
			current = nodes.top();

			if (current->val == postorder[postIndex])
			{
				nodes.pop();
				postIndex++;
			}
			else
			{
				TreeNode *newNode = new TreeNode(preorder[preIndex++]);

				if (!current->left)
				{
					current->left = newNode;
				}
				else
				{
					current->right = newNode;
				}

				nodes.push(newNode);
			}
		}

		return root;
	}
};

int main()
{
	Solution s;

	s.constructFromPrePost({1, 2, 4, 5, 3, 6, 7}, {4, 5, 2, 6, 7, 3, 1});

	return 0;
}