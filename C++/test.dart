void main() {
  String str = 'Hello, World!';
  int start = 7;
  int length = 5;

  String newStr = str.substring(0, start) + str.substring(start + length);

  print(newStr); // Outputs: 'Hello, !'
}
