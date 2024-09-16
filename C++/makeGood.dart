class Solution {
  String makeGood(String s) {
    String temp = "";

    for (int i = 0; i < s.length; i++) {
      if (temp.length != 0 &&
          (temp.codeUnitAt(temp.length - 1) - s.codeUnitAt(i)).abs() == 32)
        temp = temp.substring(0, temp.length - 1);
      else
        temp = temp + s[i];
    }

    return temp;
  }
}

void main() {
  Solution s = new Solution();
  print(s.makeGood("leEeetcode"));
}
