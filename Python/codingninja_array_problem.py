#This program is solution for question available on Coding Ninjas Platform.
#Objective of the program is to find unique element from the list , it is possible when there are many repeating quantities,
import sys
def findUnique(arr, n):
    mix = []
    mix2 = []
    for i in arr:
        if i not in mix:
            mix.append(i)
        else:
            mix2.append(i)
    for j in mix:
        if j not in mix2:
            return j


# Taking Input Using Fast I/O
def takeInput():
    print("Enter elements of list .")
    n = int(sys.stdin.readline().rstrip())
    if n == 0:
        return list(), 0
    arr = list(map(int, sys.stdin.readline().rstrip().split(" ")))
    return arr, n

# main
print("How many list do you want to check? ")
t = int(sys.stdin.readline().rstrip())

while t > 0:
    arr, n = takeInput()
    
    print("Unique element is : -",findUnique(arr, n))
    t -= 1
