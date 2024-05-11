# Asymptotic Notation Notes

## Asymptotic Notation

Pomos Needed: 1

Video: [https://www.youtube.com/watch?v=iOq5kSKqeR4](Harvard CS50 - Asymptotic Notation)
It's all about that runtime length:

1) Linear time complexity = O(n) = runtime will grow linearly with the input size
Ex: counting characters in a string one by one

2) Constant time complexity = O(1) = runtime is the same regardless of input size
Ex: predefined string length, you know how many chars there are

3) Quadratic time complexity = O(n^2) = runtime grows quadratically with input size
Ex: over time can slowdown program unless the input is really small, then it could work faster, think of a quadratic function vs a linear function's graph

4) Logarithmic time complexity = O(log n) = runtime grows to the logarithm of the input size
Ex: runtime grows very slowly compared to the input size, think of halving or the logarithm graph

## Big O Notations (general quick tutorial)

Pomos Needed: 1

Video: [https://youtu.be/V6mKVRU1evU](Big O Notations (general quick tutorial) (video))

I personally didn't get anything from this video. In summary, he was explaining big o notation using Java.

## Big Oh Notation (and Omega and Theta)

Pomos Needed: 2

Video: [https://youtu.be/ei-A_wy5Yxw?list=PL1BaGV1cIH4UhkL8a9bJGG356covJ76qN](Big Oh Notation and Omega and Theta)

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

Pomos Needed: 1

Video: [https://youtu.be/z1mkCe3kVUA](Skiena, CSE 373 -- Lecture 2, Fall 2020)

**Names of Bounding Functions:**

1) g(n) = O(f(n)) meaning C * f(n) is the upper bound on g(n)

2) g(n) = &Theta;(f(n)) meaning C&#x2081; *f(n) is an upper bound on g(n) and C&#x2082;*f(n) is the lower bound on g(n)

3) g(n) = &Omega;(f(n)) meaning C * f(n) is the lower bound on g(n)

Assuming C, C&#x2081;, and C&#x2082; are all constants independent of n.

The major point I learned from this video is that it's easier to talk about upper and lower bounds of a function than the complex function that lies in the middle of these two.

## UC Berkeley Big O

Pomos Needed: 1-2

Video: [https://archive.org/details/ucberkeley_webcast_VIS4YDpuP98](UC Berkeley Big O)

* For Big O notation, it doesn't usually matter what the constant factors are, so we can leave them out of the notation. For example, we could write O(2n), but it would be unnecessary to write the 2 because it is a constant, and therefore can be ignored.

* Algorithms that run in O(nlogn) time or faster are usually considered efficient. </br>
Whereas, algorithms that run in n^7 time or slower are usually considered useless.

* Binary search on an array:

1. Worst-case running time is O(log n)

2. Best-case running time is O(1) because it could find what you are looking for in the first attempt

3. Memory usage can be expressed as O(n)

## Amortized Analysis

Pomos Needed: 1

Video: [https://youtu.be/B3SpQZaAZP4?list=PL1BaGV1cIH4UhkL8a9bJGG356covJ76qN](Amortized Analysis)

* Definition of Amortized Analysis: method for analyzing average-case time complexities of algorithms that perform seq. of operations, where some operations are more expensive or slower than others

* The main objective is to make the average cost of each operation less or constant compared to the cost without this analysis.

* Data structures where this is used includes: Hash Tables, Disjoint Sets, and Splay Trees

* It differs from big o or worse case runtime performance because instead of giving the upper bound on the runtime of one operation, it gives us an average-case analysis of the algorithm for several operations over a given period of time.

Note: I didn't find the video helpful. I read up on the topic by referring to: [https://www.geeksforgeeks.org/introduction-to-amortized-analysis/](Introduction to Amortized Analysis)

## Computational Complexity: Section 1 & 2

Read the articles. I didn't find these articles that helpful.

## Big O Cheatsheet

* Come back to this later. It has useful graphs and charts of common dsa time complexities.

## [Review] Analyzing Algorithms (playlist) in 18 minutes

Pomos Needed: 2

Video: [https://www.youtube.com/playlist?list=PL9xmBV_5YoZMxejjIyFHWa-4nKg6sdoIv](Analyzing Algorithms)

Def: **RAM model of Computation** - the random access machine model of computation measures the runtime of an algorithm by adding up the # of steps needed to execute for a set of data

* Basic arithmetic operators and logic only take one step (+, *, =, if). Technically, it takes more operations for a machine to compute a product compared to a sum, but this model gives us simplicity.

* Loops and subroutines are complex and can take multiple steps

* Memory access takes one step

**Bound Functions**:

* Upper bound, lower bound, and tight bound - Big theta is called the middle or tight bound function

* The O in big O notation stands for "order of complexity" where the "n" on the inside represents the number of inputs. Ex: O(n)

**Time Complexities**:

* Linear time or O(n):

int addUp(int n) {
    int sum = 0
    for(int i = 0; i <= n; i++) {
        sum += i;
    }
    return sum;
}

This is linear time because it is adding up numbers one by one. If n was 100,000, it would take about 100,000 steps for it to complete, which is a lot of steps!!!

* Constant time or O(1):

int addUp(int n) {
    int sum = n * (n + 1) / 2;
    return sum;
}

This is constant time because if n was 100,000, it would only take 3 steps for this to execute. We don't care about all the small operations though, so we will shorten it to O(1) constant time.

Note: The videos weren't that helpful. I made the notes based on: </br>
[https://medium.com/@_SD10_/the-ram-model-of-computation-and-big-o-notation-a1b3cc50ec2c](The RAM Model of Computation and Big O Notation)

Video that was helpful: [https://www.youtube.com/watch?v=XMUe3zFhM5c](Learn Big O notation in 6 minutes by Bro Code)
