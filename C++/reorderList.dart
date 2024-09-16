class ListNode {
  int val;
  ListNode? next;
  ListNode([this.val = 0, this.next]);
}

class Stack<T> {
  final List<T> _stack = [];

  void push(T element) {
    _stack.add(element);
  }

  T pop() {
    if (_stack.isEmpty) {
      throw StateError("No elements in the Stack");
    } else {
      T lastElement = _stack.last;
      _stack.removeLast();
      return lastElement;
    }
  }

  T top() {
    if (_stack.isEmpty) {
      throw StateError("No elements in the Stack");
    } else {
      return _stack.last;
    }
  }

  bool isEmpty() {
    return _stack.isEmpty;
  }

  @override
  String toString() => _stack.toString();
}

class Solution {
  void reorderList(ListNode? head) {
    ListNode? temp = head;
    ListNode? temp1;

    int count = 0;

    while (temp != null) {
      count++;
      temp = temp.next;
    }

    Stack<ListNode> s = new Stack();
    temp = head;

    for (int i = 0; i < (count / 2).ceil() - 1; i++) {
      temp = temp!.next;
    }

    temp1 = temp?.next;
    temp!.next = null;
    temp = temp1;
    temp1 = head;

    while (temp != null) {
      s.push(temp);
      temp = temp.next;
    }

    while (temp1 != null) {
      temp = temp1.next;
      if (!s.isEmpty()) {
        temp1.next = s.top();
        s.pop();

        temp1.next!.next = temp;
      } else {
        if (temp1.next != null) temp1.next!.next = temp;
      }
      temp1 = temp;
    }
  }
}

int main() {
  Solution s = Solution();
  ListNode? head =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  s.reorderList(head);

  while (head != null) {
    print(head.val);
    head = head.next;
  }

  return 0;
}
