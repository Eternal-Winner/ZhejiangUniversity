# 11-Hash 4 Hashing-Hard Version #Hash

## Describe
Given a hash table of size N, we can define a hash function H(x)=x%N. Suppose that the linear probing is used to solve collisions, 
we can easily obtain the status of the hash table with a given sequence of input numbers.

However, now you are asked to solve the reversed problem: reconstruct the input sequence from the given status of the hash table.
Whenever there are multiple choices, the smallest number is always taken.

### Input Specification:

Each input file contains one test case. For each test case, the first line contains a positive integer N (≤1000), 
which is the size of the hash table. The next line contains N integers, separated by a space. A negative integer 
represents an empty cell in the hash table. It is guaranteed that all the non-negative integers are distinct in the table.

### Output Specification:

For each test case, print a line that contains the input sequence, with the numbers separated by a space. 
Notice that there must be no extra space at the end of each line.

### Sample Input:

```in
11
33 1 13 12 34 38 27 22 32 -1 21
```

### Sample Output:

```out
1 13 12 21 33 34 38 27 22 32
```

```
Code Size Limit16 KB
Time Limit 400 ms
Memory Limit 64 MB
```

# Thought
1. 依次扫描给定序列中的元素，根据插入哈希表的规则确定表中各元素的前置元素个数，根据给定元素序列表中各各元素的下标和前置元素的个数来给定入度表中的值。
   1. 确定插入顺序时，将前置元素与当前元素的关系在二维数组中确定为连通态（后续操作中根据该二维数组来对入度进行操作）。
2. 将入度表中入度为0的元素压入队列
3. 取队列中最小的元素出队，更新入度表
4. 检查入度表中是否所有元素都已入队，如果全部入队，则依次将队列中元素按从小到大的元素出队，如果没有全部入队，则执行步骤3。