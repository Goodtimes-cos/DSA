"""Attempt at implementing the nth Fibonacci number problem"""
# Very simple solution, but we have a problem. It's very slow! Very, very slow!
def nFib(n):
    if n == 0:
        return 0
    elif n <= 2:
        return 1
    else:
        return nFib(n-1) + nFib(n-2)

# To see why it's slow, we must draw the recursion diagram.
# What is the time complexity? T_n = T_n-1 + T_n-2 + O(1) = \phi^n = (1+sqrt(5) / 2)^n, which is very slow!
# T_n >= 2T_n-2, so we have time complexity at least O(2^{n/2})

# We can solve this problem using a technique known as memoization
# Idea is to remember the computation of each fibonacci number, and compute it at most once!

memo = {}
def nMemFib(n):
    if n in memo:
        return memo[n]

    if n == 0:
        result = 0
    elif n <= 2:
        result = 1
    else:
        result = nMemFib(n-1) + nMemFib(n-2)
    
    memo[n] = result
    return result

# Notice that the memoization solution is very similar to that of the naive approach. More generally, we
# can apply this method to any recursive process

# My guess for the time complexity. We make, at most, n calculations that are not O(1). So, we have time complexity O(n)?
# This is the fundamental idea of dynamic programming:
# DP = Recursion + Memoization

# Remember the solutions, and try to use them to solve bigger problems.
# This is why the hardest part of solving a dynamic programming problem is figuring out what sub-problems we can use to solve the problem.

# We can also implement the solution to a dynamic programming problem using a bottom-up approach, which allows us to save memory.
# This is a beautiful solution!
def fib(n):
    memo = {}
    for i in range(1, n+1):
        if i <= 2:
            result = 1
        else:
            # We assume that the previous two entires of the Fibonacci sequence have already been computed.
            # For this reason, it is always important to solve the dependencies of a sub-problem first.
            # Hence, we have to solve the sub-problems in topological sort order. The diagram for the topological sort order is simple for this.
            # One key thing to consider is that if the topological sort order is cyclical, then we cannot solve the problem using this method.
            result = memo[i-1] + memo[i-2]

        memo[i] = result
    return memo[n]

for i in range(0, 100):
    print(nMemFib(i))