class Solution {
  int firstMissingPositive(List<int> nums) {
    for (int i = 0; i < nums.length; i++)
      if (nums[i] <= 0) nums[i] = nums.length + 1;

    for (int i = 0; i < nums.length; i++)
      if (nums[i] <= nums.length)
        nums[nums[i] - 1] = (nums[nums[i] - 1].abs()) * -1;

    for (int i = 0; i < nums.length; i++) if (nums[i] > 0) return i + 1;

    return nums.length + 1;
  }
}
