# 2081. Sum of k-Mirror Numbers
Hard
---
A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.

For example:

- 9 is a 2-mirror number. Its representation in base-10 is 9, and in base-2 is 1001, both of which are palindromes.

- 4 is not a 2-mirror number because its base-2 form is 100, which is not a palindrome.

Given the base k and the number n, return the sum of the n smallest k-mirror numbers.

### Example 1
```
Input: k = 2, n = 5  
Output: 25  
Explanation:  
The 5 smallest 2-mirror numbers and their base-2 representations are:

  base-10    base-2  
    1          1  
    3         11  
    5         101  
    7         111  
    9        1001  

Sum = 1 + 3 + 5 + 7 + 9 = 25.
```

### Example 2
```
Input: k = 3, n = 7  
Output: 499  
Explanation:  
The 7 smallest 3-mirror numbers and their base-3 representations are:

  base-10    base-3  
    1          1  
    2          2  
    4         11  
    8         22  
   121      11111  
   151      12121  
   212      21212  

Sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
```
### Example 3
```
Input: k = 7, n = 17  
Output: 20379000  
Explanation:  
The 17 smallest 7-mirror numbers are:  
1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
```

# Constraints
```
- 2 <= k <= 9

- 1 <= n <= 30

```
