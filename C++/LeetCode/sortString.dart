class Solution {
  String customSortString(String order, String s) {
    Map<String, int> m = new Map();

    for (int i = 0; i < s.length; i++)
      if (m.containsKey(s[i]) == false) {
        m[s[i]] = 0;
        m[s[i]] = (m[s[i]]! + 1);
      }
    String ans = "";

    for (int i = 0; i < order.length; i++) {
      if (m.containsKey(order[i]) == true) {
        String temp = order[i] * m[order[i]]!;
        ans += temp;
        m.remove(order[i]);
      }
    }

    m.forEach((k, v) {
      String temp = k * v;
      ans += temp;
    });

    return ans;
  }
}

void main() {
  Solution s = new Solution();
  print(s.customSortString("cba", "abcd"));
}
