import 'dart:math';

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}

class Solution {
  int maxim = -1;

  int solve(TreeNode? root) {
    if (root == null) return 0;

    int a = solve(root.left);
    int b = solve(root.right);

    if (a + b > maxim) maxim = a + b;

    return max(a, b) + 1;
  }

  int diameterOfBinaryTree(TreeNode? root) {
    solve(root);

    return maxim;
  }
}

void main() {
  Solution solution = new Solution();
  TreeNode root = new TreeNode(
      1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
  print(solution.diameterOfBinaryTree(root));
}
