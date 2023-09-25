Given an integer **N** which represents the number of cards in a deck. The deck is ordered from **1** to **N** where **1** is the topmost card and **N** is at the bottom. You take out the topmost card from the deck and insert it at the bottom and throw the next card that appears at the top of the deck. Again you do the same thing until a single card remains. The task is to find the number of the card that remains at the end.

**Examples:**

```
**Input:** N = 4 
**Output:** 1
1 2 3 4
^     ^
Top   Bottom

Operation 1: 3 4 1 (1 got shifted to the bottom and 2 got removed)
Operation 2: 1 3 (3 got shifted and 4 got removed)
Operation 3: 1 (3 got removed after shifting 1)

**Input:** N = 10
**Output:** 5
```