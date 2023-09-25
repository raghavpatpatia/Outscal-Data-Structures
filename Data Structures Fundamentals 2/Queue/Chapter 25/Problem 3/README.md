The Kira learned about priority queues recently and asked his teacher for an interesting problem. So his teacher came up with a simple problem. He now has an integer array A. For each index i, he wants to find the product of the largest, second largest and the third largest integer in the range _*[1,i]*_. <br>

**Note** :- All numbers will be distinct in array. <br>

**Input** :- <br>
The first line contains an integer N, denoting the number of elements in the array A. <br>
The next line contains N space separated integers, each denoting the ith integer of the array A.

**Output** :- <br>
Print the answer for each index in each line. If there is no second largest or third largest number in the array A upto that index, then print "-1", without the quotes.

**Constraints** :- <br>
1 <= N <= 100000 <br>
1 <= A[i] <= 100000 <br>

**Sample Input** :- <br>
5 <br>
1 2 3 4 5 <br>
**Sample Output** :- <br>
-1 <br>
-1 <br>
6 <br>
24 <br>
60 <br>