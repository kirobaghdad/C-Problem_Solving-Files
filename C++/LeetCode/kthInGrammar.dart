import 'dart:math';

class Solution {
  int solve(int n, int k, {int i = 2, String s = "01"}) {
    if (i != n) {
      String temp = "";

      if (pow(2, n - 2) >= k) {
        for (int l = 0; l < s.length / 2; l++)
          if (s[l] == "0")
            temp += "01";
          else
            temp += "10";
        return solve(n, k, i: i + 1, s: temp);
      } else {
        for (int l = (s.length / 2).floor(); l < s.length; l++)
          if (s[l] == "0")
            temp += "01";
          else
            temp += "10";
        return solve(n, k - pow(2, n - 2) as int, i: i + 1, s: temp);
      }
    }
    return int.parse(s[k - 1]);
  }

  int kthGrammar(int n, int k) {
    if (n == 1) return 0;
    return solve(n, k);
  }
}

void main() {
  Solution s = new Solution();
  print(s.kthGrammar(4, 8));
}
