# Disjoint Sets Union ( DSU )

The Disjoint-Set data structure (also called the union-find data structure), keeps track of elements partitioned in non overlapping subsets i.e, **Disjoint Sets**.  

It offers useful operations such as :

- ```unionSets()``` : To merge the two sets to which the given elements belong.
- ```findSetId()``` : To find leader / parent of a set to which an element belongs.
- ```areInSameSet()``` : To check if 2 given elements belong to the same set.
- ```getSetSize()``` : Get the size of a given **Disjoint Component**.
- ```getSetsCount()``` : Get the number of **Disjoint Sets** represented in the DSU.

Since this data structure is easy to implement, it's use can be seen extensively in problems related to graph connectivity.

More formally, two sets are said to be **Disjoint** if their intersection ```ϕ``` i.e. ```NULL```. Therefore, a Disjoint-Set is a Data Structure that keeps and tracks the records of a set of elements partitioned into several non-overlapping (Disjoint) subsets.

For Example, let there be 3 sets :

- ```A := {1, 2, 3, 4, 5}```
- ```B := {3, 5, 9, 12}```
- ```C := {6, 7, 18, 21}```

| Intersection                      | Result                                     |
| ----------------------------------|:------------------------------------------:|
| ```A and B```                     | ```{3, 5} -> Not Disjoint```               |
| ```A and C```      | ```{} -> Disjoint```                       |

## DSU Structure

The DSU comprises of multiple componenets and internal states coming together to represent all the **Disjoint Sets** formed by the given set of elements.

In the implementation provided, the DSU utilizes the presence of 3 primary variables

- ```int setsCount``` : It is used to keep a track of the count of the number of **Disjoint Sets** currently represented by the DSU.  
```initial value : set to n, passed as argument to constructor```

- ```vector<int> siz``` : It is a vector which is responsible for storing the size of the **Disjoint Set** to which a particular element belongs, i.e. ```siz[i]``` tells us the size of the **Disjoint Set** to which the ```ith``` element belong to.  
```initial value : size = n, all values set to 1```

- ```mutable vector<int> par``` : It is a vector which is used to store the parent of the **Disjoint Set** to which a particular element belongs, i.e. ```par[i]``` returns the id of the parent of the **Disjoint Set** to which the ```ith``` element belongs to.  
```initial value : size = n, all values set to their respective indices as initially every element is a parent of itself.```

We can build the DSU ```O(n)``` as follows :

```C++
/**
 * Initializes the DSU with "n" independent sets.
 *
 * @param n the number of sets to initialize.
*/
DSU(int n) {
    setsCount = n;
    siz.resize(n, 1);
    par.resize(n);
    iota(par.begin(), par.end(), 0);
}
```

## Full Implementation

You can find the full implementation of the sparse table [here](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/src/data_structures/disjoint_sets_union/disjoint_sets_union.cpp).

The above implementation of a DSU represents it in its most basic form and can be used as a template in order to derieve more powerful versions based on requirements.

## Problems

```Coming up soon !```
