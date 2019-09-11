# Sparse Table

Sparse table is a data structure that can help us answer range queries on a set on static data (i.e. data that does not change regularly).<br>
Sparse table does pre-processing on the data first, then it can answer range queries efficiently.

More formally, sparse table can calculate the answer of **_Q(l, r)_** on an array **_a[i]_** of length **_n_**.<br>
Where **_Q(l, r)_** can be any _duplicate-invariant function_ as...
- max
- min
- GCD
- LCM

What I mean by _duplicate-invariant function_ is any function that output the same value for duplicate inputs.<br>
So for example:<br>

| Function                          | Description                                |
| ----------------------------------|:------------------------------------------:|
| _min(2, 3) = min(2, 2, 3, 3) = 2_ | minimum is _duplicate-invariant function_  |
| _(2 + 3) != (2 + 2 + 3 + 3)_      | addition is not _duplicate-invariant_.     |

## Sparse Table Structure
The structure of sparse table is a 2D array **_ST[j][i]_**,<br>
where the **_j_**-th row in the sparse table holds the answer of queries of length **2^j**.

More formally, **_ST[j][i]_** holds the value of **_Q(i, i + (2^j) - 1)_**

We can build the sparse table easily in **_O(n.log(n))_** as follows (having **_Q()_** equals **_min()_** as an example):

```C++
for (int i = 0; i < n; ++i) {
    ST[0][i] = a[i];
}

// Note that (1 << j) is equivalent to pow(2, j)

for (int j = 1; (1 << j) <= n; ++j) {
    for (int i = 0; (i + (1 << j)) <= n; ++i) {
        int x = ST[j - 1][i];
        int y = ST[j - 1][i + (1 << (j - 1))];

        ST[j][i] = min(x, y);
    }
}
```
## Sparse Table Query
Now in order to calculate any **_Q(l, r)_** we are going to use the _duplicate-invariant_ property to get the answer in **_O(1)_** as follows:

```C++
// LOG is a pre-computed array where LOG[i] = floor(log2(i))

int g = LOG[r - l + 1];

int x = ST[g][l];
int y = ST[g][r - (1 << g) + 1];

return min(x, y);
```

## Full Implementation
You can find the full implementation of the sparse table [here](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/data_structures/sparse_table/sparse_table.cpp).

The above implementation is an example of sparse table the computes the index of the minimum element in the range **_[L, R]_**

## Problems
1. [Codeforces CGCDSSQ](http://codeforces.com/contest/475/problem/D) => [Solution](http://codeforces.com/contest/475/submission/19443560)
