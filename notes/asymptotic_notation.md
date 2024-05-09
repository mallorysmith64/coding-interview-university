# Notes

## Asymptotic Notation

Pomos Needed: 1

Video: [https://www.youtube.com/watch?v=iOq5kSKqeR4](Asymptotic Notation)
It's all about that runtime length:

1) Linear time complexity = O(n) = runtime will grow linearly with the input size
Ex: counting characters in a string one by one

2) Constant time complexity = O(1) = runtime is the same regardless of input size
Ex: predefined string length, you know how many chars there are

3) Quadratic time complexity = O(n^2) = runtime grows quadratically with input size
Ex: over time can slowdown program unless the input is really small, then it could work faster, think of a quadratic function vs a linear function's graph

4) Logarithmic time complexity = O(log n) = runtime grows to the logarithm of the input size
Ex: runtime grows very slowly compared to the input size, think of halving or the logarithm graph

## Big O Notation

Pomos Needed: 1

Video: [https://youtu.be/V6mKVRU1evU](Big O Notations)

I personally didn't get anything from this video. In summary, he was explaining big o notation using Java.

## Big Oh Notation (and Omega and Theta)

Pomos Needed: 2

Video: [https://youtu.be/ei-A_wy5Yxw?list=PL1BaGV1cIH4UhkL8a9bJGG356covJ76qN](Big Oh Notation (and Omega and Theta))

The formal mathematical notation for Big O notation is as follows: </br>
f(n) = O(g(n)) if c and n, </br>
|f(n)| &leq; C*g(n) for all n &GreaterEqual; n&#x2080;

This definition is read as f(x) is big O of g(x) if the absolute value of f(x) is at most a positive constant multiple of g(x) for all large values of x.

I got the formal definition out of this video, and I learned about big theta and big omega.

* Big O describes the worst-case performance of an algorithm, think of the horror
* Big Theta describes the average case, think of the typical case
* Big Omega represents the best case performance for an algorithm, think of utopia
This means that Big O sets an upper bound for how slow code can be, and Big Omega sets the lower bound for fast it can perform.

## Skiena video

Pomos Needed: 2

Video: [https://youtu.be/z1mkCe3kVUA](Skiena video, CSE 373 -- Lecture 2, Fall 2020)

**Names of Bounding Functions:**

1) g(n) = O(f(n)) meaning C * f(n) is the upper bound on g(n)

2) g(n) = &Theta;(f(n)) meaning C&#x2081; *f(n) is an upper bound on g(n) and C&#x2082;*f(n) is the lower bound on g(n)

3) g(n) = &Omega;(f(n)) meaning C * f(n) is the lower bound on g(n)

Assuming C, C&#x2081;, and C&#x2082; are all constants independent of n.

The major point I learned from this video is that it's easier to talk about upper and lower bounds of a function than the complex function that lies in the middle of these two.
