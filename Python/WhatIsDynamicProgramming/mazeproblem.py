"""
Given an NxN grid, in how many ways can a rabbit get from the
top-left to the bottom-right corner if it can only move down or right?
"""

# We first define a sub-problem
# We use the goal as the sub-problem
# Imagine a 6x9 grid. If we go down, we reduce to problem to a
# 5x9 grid. If we go left, we reduce the problem to a 5x8 problem.
# Once the rabbit gets to the right hand corner, 1x1, we have no
# moves left
# It's often useful to consider corner cases like this one,
# when trying to construct a base case.

memo = {}
def waysToMove(M, N):
    if M == 1 and N == 1:
        return 1
    elif M == 1:
        """
        if (M,N-1) in memo:
            return 1 + memo[(M,N-1)]
        else:
            memo[(M,N-1)] = waysToMove(M, N-1)    
            return 1 + memo[(M,N-1)]
        """
        return 0
    elif N == 1:
        """
        if (M-1,N) in memo:
            return 1 + memo[(M-1,N)]
        else:
            memo[(M-1,N)] = waysToMove(M-1, N)    
            return 1 + memo[(M-1,N)]
        """
        return 0
    else:
        if (M-1, N) in memo and (M, N-1) in memo:
            return 1 + memo[(M-1,N)] + memo[(M, N-1)]
        elif (M-1, N) in memo:
            memo[(M, N-1)] = waysToMove(M, N-1)
            return 1+ memo[(M-1, N)] + memo[(M,N-1)]
        elif (M, N-1) in memo:
            memo[(M-1, N)] = waysToMove(M-1, N)
            return 1+ memo[(M, N-1)] + memo[(M-1, N)]
        else:
            memo[(M, N-1)] = waysToMove(M, N-1)
            memo[(M-1, N)] = waysToMove(M-1, N)
            return 1 + memo[(M, N-1)] + memo[(M-1, N)]
    
print(waysToMove(18,6))

# My way, as is usual now, is wrong. See below for good solution!

def grid_paths(n, m):
    memo = {}
    for i in range(0, n+1):
        memo[(i, 1)] = 1
    for j in range(1, m+1):
        memo[(1, j)] = 1
    
    for i in range(2, n+1):
        for j in range(2, m+1):
            memo[(i, j)] = memo[(i-1, j)] + memo[(i, j-1)]
    
    return memo[(n, m)]

print(grid_paths(18,16))