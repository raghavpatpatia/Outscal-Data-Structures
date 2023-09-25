Kira just purchased a queue and wants to perform N operations on the queue. The operations are of following type:

_E x_ : Enqueue x in the queue and print the new size of the queue.

_D_ : Dequeue from the queue and print the element that is deleted and the new size of the queue separated by space. If there is no element in the queue then print -1 in place of deleted element.

Kira needs your help to solve the above problem.

**Input** :- <br>
First line consists of a single integer denoting N. <br>
Each of the following N lines contain one of the operation as described above.

**Output** :- <br>
For each enqueue operation print the new size of the queue. And for each dequeue operation print two integers, deleted element (-1, if queue is empty) and the new size of the queue.

**Constraints** :- <br>
1 <= N <= 100 <br>
1 <= x <= 100 <br>

**Sample Input** :- <br>
5 <br>
E 2 <br>
D <br>
D <br>
E 3 <br>
D <br>
**Sample Output** :- <br>
1 <br>
2 0 <br>
-1 0 <br>
1 <br>
3 0 <br>