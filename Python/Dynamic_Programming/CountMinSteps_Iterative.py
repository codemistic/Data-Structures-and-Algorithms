# QUESTION : Given a positive integer 'n', find and return the minimum number of steps 
    # that 'n' has to take to get reduced to 1. You can perform
        #  any one of the following 3 steps:
# 1.) Subtract 1 from it. (n = n - ­1) ,
# 2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
# 3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ). 

# Now solve this iteratively :

from sys import stdin
from sys import maxsize as MAX_VALUE



def countMinStepsToOne(n,dp) :
    dp[0] = 0
    dp[1] = 0
    i = 2 
    while i<=n:
        ans1 = dp[i-1]
        ans2 = i-1
        if i%2 == 0:
            ans2 = dp[i//2]
        ans3 = i-1
        if i%3 == 0:
            ans3 = dp[i//3]
        ans = 1 + min(ans1,ans2,ans3)
        dp[i] = ans
        i += 1
    return dp[n]


#main
n = int(stdin.readline().rstrip())
dp = [-1 for i in range(n+1)]
print(countMinStepsToOne(n,dp))
