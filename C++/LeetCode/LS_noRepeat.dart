class Solution {
  int lengthOfLongestSubstring(String s) {
    Map<String, int> map = new Map<String, int>();

    int l = double.minPositive.toInt();
    int start = 0;

    for (int i = 0; i < s.length; i++) {
      if (map.containsKey(s[i]) == true) {
        if (i - start > l) l = i - start;

        for (int k = start; k < map[s[i]]!; k++) map.remove(s[k]);

        start = (map[s[i]]! + 1);
      }

      map[s[i]] = i;
    }

    if (s.length - start > l) l = s.length - start;

    return l;
  }
}

void main() {
  Solution s = new Solution();
  print(s.lengthOfLongestSubstring(" "));
}
