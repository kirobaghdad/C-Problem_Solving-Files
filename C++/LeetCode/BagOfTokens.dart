class Solution {
  int bagOfTokensScore(List<int> tokens, int power) {
    int i = 0;
    int j = tokens.length - 1;
    int ans = 0;

    tokens.sort();

    while (i < j) {
      if (power >= tokens[i]) {
        ans++;
        power -= tokens[i];
        i++;
      } else {
        if (ans == 0) return 0;

        power += tokens[j];
        j--;
        ans--;
      }
    }

    if (i == j && power >= tokens[i]) ans++;

    return ans;
  }
}

void main() {
  Solution s = new Solution();
  print(s.bagOfTokensScore([100, 200, 300, 400], 200));
}
