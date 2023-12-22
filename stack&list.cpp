// Stacks
void main() 
{
  // Challenge1: Reverse a List
  List<int>myList= [1, 2, 3, 4, 5];
  print("reversed List: ${reverseList(myList)}");
  // challenge 2: Balance the Parentheses
  String expression = "((a + b) * (c - d))";
  print("Balanced Parentheses: ${isBalanced(expression)}");
}

List<T> reverseList<T>(List<T> list) 
{
  return List.from(list.reversed);
}

bool isBalanced(String expression) 
{
  int count = 0;
  for (var char in expression.split(''))
  {
    if (char == '(') 
    {
      count++;
    } else if (char == ')')
    {
      count--;
      if (count < 0) {
        return false;
      }
    }
  }
  return count == 0;
}

// Linked List
class Node {
  dynamic data;
  Node next;

  Node (this.data);
}

void main() {
  // Challenge 1: Print in Reverse
  Node head = Node(1);
  head.next = Node(2);
  head.next.next = Node(3);
  print("Linked List in Reverse Order:");
  printInReverse(head);

  // Challenge 2: Find the Middle Node
  Node middleNode = findMiddleNode(head);
  print("Middle Node: ${middleNode.data}");

  // Challenge 3: Reverse a Linked List
  Node reversedHead = reverseLinkedList(head);
  print("Reversed Linked List:");
  printInReverse(reversedHead);

  // Challenge 4: Remove All Occurrences
  Node updatedList = removeAllOccurrences(reversedHead, 2);
  print("Updated Linked List after removing all occurrences of 2:");
  printInReverse(updatedList);
}

void printInReverse(Node node) {
  if (node == null) return;
  printInReverse(node.next);
  print(node.data);
}

Node findMiddleNode(Node head) {
  if (head == null) return null;

  Node slow = head;
  Node fast = head;

  while (fast != null && fast.next != null) {
    slow = slow.next;
    fast = fast.next.next;
  }

  return slow;
}

Node reverseLinkedList(Node head) {
  Node prev = null;
  Node current = head;
  Node nextNode;

  while (current != null) {
    nextNode = current.next;
    current.next = prev;
    prev = current;
    current = nextNode;
  }

  return prev;
}

Node removeAllOccurrences(Node head, dynamic target) {
  Node dummy = Node(0);
  dummy.next = head;
  Node current = dummy;

  while (current.next != null) {
    if (current.next.data == target) {
      current.next = current.next.next;
    } else {
      current = current.next;
    }
  }

  return dummy.next;
}