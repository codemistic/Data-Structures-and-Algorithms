# write a program to find all pairs of integers whose sum is equal to a given number.
 
def findpairs(arr,target):
    for i in range(len(arr)):
        for j in range(i+1,len(arr)):
            if arr[i]==arr[j]:
                continue
            elif arr[i]+arr[j]==target:
                print(i,j)

            

findpairs([1,2,3,2,3,4,5,6],6)
