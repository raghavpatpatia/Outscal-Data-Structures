Given a linked list and a value _x_, partition it such that all nodes less than _x_ come before nodes greater than or equal to _x_.

You should preserve the original relative order of the nodes in each of the two partitions.

**Example:**

```
Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

Exaplanation :- 
Nodes having value less than x in original order -
  1 -> 2 -> 2
Similarly, nodes having value greater than or equal to x in original order -
  4 -> 3 -> 5
So the final linked list will be -
  1 -> 2 -> 2 -> 4 -> 3 -> 5
```