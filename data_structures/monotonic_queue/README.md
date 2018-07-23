# Monotonic Queue

Monotonic queue is a data structure where the order of its element changes monotonically. That is, they are either non-decreasing or non-increasing.

So, with the help of the monotonic behavior, we can build a data structure that can act as a basic queue but with the ability to answer the following questions in **_O(1)_**:
- What is the maximum value in the queue so far?
- What is the minimum value in the queue so far?

In the following section, I will discuss two ways of implementing the monotonic queue:
- one way using two stacks,
- the other way using double ended queue.

## Implementation
In the following discussion, I will discuss only the idea behind how to implement a monotonic queue that can find the maximum value so far.
But finding the minimum element is essentially the same, and will be provided in the code implementation.

### Two Stacks
One can recall from basic data structure courses or tutorials that we can implement a queue using two stacks in the following manner:
- Dedicate one of the two stacks (say **_S1_**) for **_push_** operations only.
- Dedicate the other stack (say **_S2_**) for **_pop_** operations only.
- Whenever we want to **_push_** an element into the queue, we will push it to **_S1_**.
- Whenever we want to **_pop_** an element from the queue, we will pop it from **_S2_**.
- Whenever **_S2_** is empty during the **_pop_** operation, we will flip **_S1_** into **_S2_**.

In that way we can implement a queue using two stacks.

In order to implement a monotonic queue, we will essentially do a similar approach but with few modifications.<br>
Instead of storing only the pushed element in the stack, we will store also the maximum element so far during the **_push_** operation.
That is, every node in the stack will hold a pair of values:
- the actual pushed value, and
- the maximum value so far in the stack.

So if we pushed a new value **_x_** in the stack, we will do the following operation:
```C++
newNode = { x, max(x, stack.top().max) };
stack.push(newNode);
```
Now by applying the previous steps to both of the stacks separately, we can find the maximum value in **_O(1)_**.

To find the maximum value we will simply return `max(S1.top().max, S2.top().max)`.

#### Complexity
The complexity of this implementation is **_O(1)_**.
That is because every element will be inserted in either stacks at most once and will be removed at most once.

#### Code
You can find a complete code for the monotonic queue implemented by two stacks in this [link](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/data_structures/monotonic_queue/monotonic_queue_using_stacks.cpp).

### Double Ended Queue
In this implementation, in order to find the maximum value pushed in the queue so far, we will use a double ended queue (say **_deq_**) (i.e. a simple queue but can be accessed from either ends: front, or back).

We will also need a basic queue (say **_que_**) to store the actual elements.

Now I will discuss the 3 basic operations:

#### Push
Whenever we need to push a new value (say **_x_**) into the queue, we will push it at the back of the double ended queue.
But before that, we will keep removing elements from the back as long as their values are smaller that **_x_**
```C++
while (deq.size() > 0 && deq.back() < x) {
	deq.pop_back();
}

deq.push_back(x);
que.push(x);
```
Thus, by applying the previous operation we will maintain the values in the double ended queue to be monotonically non-decreasing.

#### Get Maximum
By applying the previous operation, we can simply find the maximum value in the queue to be the front value of the double ended queue.

```C++
max = deq.front();
```

#### Pop
During **_pop_** operation, we will simply pop the front value (say **_x_**) of **_que_**, and we will also remove the front value of the **_deq_** whenever it matches **_x_**.

```C++
if (deq.front() == que.front()) {
	deq.pop_front();
}

que.pop();
```

#### Complexity
The complexity of this implementation is **_O(1)_**.
That is because every element will be inserted in the double ended queue at most once and will be removed at most once.

#### Code
You can find a complete code for the monotonic queue implemented by double ended queue in this [link](https://github.com/OmarBazaraa/Competitive-Programming/blob/master/data_structures/monotonic_queue/monotonic_queue.cpp).

## Problems
1. [Codeforces Exposition](http://codeforces.com/contest/6/problem/E) => [Solution](http://codeforces.com/contest/6/submission/40634813)