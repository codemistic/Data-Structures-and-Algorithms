# dynamic programming is like a recursion but here we will only deal with the case the 
    # subproblem is repeating itself.


# Fibonacci solution with the help of DP : 

def fibonacci(n,dp):
    if n == 1 or n == 0:		# base case
        return n
    if dp[n-1] == -1:			# checking if value is not stored in the dp array
        ans1 = fibonacci(n-1,dp)
        dp[n-1] = ans1			# Also update the dp array after finding the value.
    else:				# if stored in the dp array then just use that value from there.
        ans1 = dp[n-1]
    if dp[n-2] == -1 :
        ans2 = fibonacci(n-2,dp)
        dp[n-2] = ans2
    else:
        ans2 = dp[n-2]

    return ans1 + ans2


# Iterative solution :

def fibbI(n):
    dp = [0 for i in range(n+1)] 		# creating a dp array within the function
    dp[0] = 0 
    dp[1] = 1
    i = 2
    while i<=n:
        dp[i] = dp[i-1] + dp[i-2] 		# make a relation between the dp array elements by using the recursive relation.
        i+=1
    return dp[n]


# main

n= int(input())
dp = [-1 for i in range(n+1)]
print(fibonacci(n,dp))
print(fibbI(n))
