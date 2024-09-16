class Solution {
  int maxSubarrayLength(List<int> nums, int k) {
    var m = new Map();

    int ans = -double.maxFinite.toInt();
    int j = 0;
    int i = 0;

    while (j < nums.length) {
      if (m.containsKey(nums[j]) == true)
        m[nums[j]]++;
      else
        m[nums[j]] = 1;

      if (m[nums[j]] > k) {
        if (j - i > ans) ans = j - i;

        while (i < nums.length && nums[i] != nums[j]) {
          m[nums[i]]--;
          i++;
        }

        m[nums[j]]--;

        i++;
      }

      j++;
    }

    if (j - i > ans) ans = j - i;

    return ans;
  }
}

void main() {
  Solution s = new Solution();

  print(s.maxSubarrayLength([1, 2, 3, 1, 2, 3, 1, 2], 2));
}
