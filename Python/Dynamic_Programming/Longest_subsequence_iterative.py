# QUESTION : Given an array with N elements, you need to find the length of the 
    # longest subsequence in the given array such that all elements of the subsequence 
        # are sorted in strictly increasing order.


# solve this by iterative method : 


from sys import stdin

def lis(arr,n): 
    dp = [[0 for i in range(2)] for _ in range(n+1)]
    
    for i in range(n-1,-1,-1):

        including_subsequence = 1
        for j in range(i+1,n):
            if arr[j]>arr[i]:
                ans = dp[j][0]
                including_subsequence = max(including_subsequence,1+ans)
        dp[i][0] = including_subsequence
        excluding_max = dp[i+1][1]
        overall_max = max(including_subsequence,excluding_max)
        dp[i][1] = overall_max
    
    return dp[0][1]



def takeInput():
    #To take fast I/O
    n=int(stdin.readline().strip())
    if n==0:
        return list(),0
    arr=list(map(int,stdin.readline().strip().split( )))
    return arr,n
    

arr,n=takeInput()

ans = lis(arr,n)
print(ans)
