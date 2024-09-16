class Solution {
  int maxFrequencyElements(List<int> nums) {
    int ans = 0;
    Map<int, int> m = Map();
    int max = -1;

    for (int i = 0; i < nums.length; i++) {
      // m[nums[i]] = (m[nums[i]]! + 1);

      if (m.containsKey(nums[i]) == false)
        m[nums[i]] = 1;
      else
        m[nums[i]] = m[nums[i]]! + 1;

      if (m[nums[i]]! > max) {
        max = m[nums[i]]!;
        ans = m[nums[i]]!;
      } else if (m[nums[i]] == max) ans += m[nums[i]]!;
    }

    return ans;
  }
}

void main() {
  Solution s = new Solution();
  List<int> nums = [1, 2, 2, 3, 1, 4];
  print(s.maxFrequencyElements(nums));
}
