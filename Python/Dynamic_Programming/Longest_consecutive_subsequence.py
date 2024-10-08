# QUESTION : Given an array with N elements, you need to find the length of the 
    # longest subsequence in the given array such that all elements of the subsequence 
        # are sorted in strictly increasing order.

from sys import stdin

def lis(arr,i,n,dp): 
    if i == n:
        return 0,0
    including_subsequence = 1

    for j in range(i+1,n):
        if arr[j]>arr[i]:
            if dp[j] == -1:
                result = lis(arr,j,n,dp)
                dp[j] = result
                ans = result[0]
            else:
                ans = dp[j][0] 

            including_subsequence = max(including_subsequence,ans+1)

    if dp[i+1] == -1:
        result = lis(arr,i+1,n,dp)
        dp[i+1] = result
        excluding_subsequence = result[1]
    else:
        excluding_subsequence = dp[i+1][1]

    overall_max_subsequence = max(excluding_subsequence,including_subsequence)

    return including_subsequence , overall_max_subsequence
  

def takeInput():
    #To take fast I/O
    n=int(stdin.readline().strip())
    if n==0:
        return list(),0
    arr=list(map(int,stdin.readline().strip().split( )))
    return arr,n
    

arr,n=takeInput()
dp = [-1 for i in range(n+1)]
ans = lis(arr,0,n,dp)[1]
print(ans)