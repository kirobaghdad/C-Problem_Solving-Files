class Solution {
  int getCommon(List<int> nums1, List<int> nums2) {
    Set<int> s = new Set();

    for (int i = 0; i < nums1.length; i++) {
      s.add(nums1[i]);
    }

    for (int i = 0; i < nums2.length; i++)
      if (s.contains(nums2[i])) return nums2[i];

    return -1;
    // int m = 0;
    // int i = 0;

    // if (nums1[0] > nums2[0]) {
    //   m = nums1[0];
    //   i = 1;
    // } else if (nums1[0] < nums2[0]) {
    //   m = nums2[0];
    //   i = 2;
    // } else
    //   return nums1[0];

    // if (i == 1) {
    //   int j = 0;
    //   while (j < nums2.length && nums2[j] <= m) if (nums2[j] == m) return m;
    //   return -1;
    // } else {
    //   int j = 0;
    //   while (j < nums1.length && nums1[j] <= m) if (nums1[j] == m) return m;
    //   return -1;
    // }
  }
}
