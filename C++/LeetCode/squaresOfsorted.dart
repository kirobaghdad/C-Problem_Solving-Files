import 'dart:math';

class Solution {
  List<int> sortedSquares(List<int> nums) {
    final ans = List<int>.empty(growable: true);

    for (int i = 0; i < nums.length; i++) {
      ans.add(pow(nums[i], 2).toInt());
    }
    ans.sort();
    // final ans = SplayTreeMap<int, int>();

    // for (int i = 0; i < nums.length; i++) {
    //   num t = pow(nums[i], 2);
    //   ans[i] = t.toInt();
    // }

    // List<int> n = ans.entries.map((e) => e.key).toList();

    return ans;
  }
}

void main() {
  Solution s = new Solution();
  print(s.sortedSquares([-4, -1, 0, 3, 10]));
}
