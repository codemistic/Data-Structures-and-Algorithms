# 1..TO FIND FACTORIAL OF A NUMBER USING RECURSION

def factorial(n):
    assert n>=0 and int(n)==n , "the number must be positive integer only"
    if n==0 or n==1:
        return 1
    else:
        return n*factorial(n-1)

print(factorial(4))





# 2..TO PRINT FIBONACCI SERIES

def fibonacci(n):
    assert n>=0 and int(n)==n , "only positive integers"
    if n==0 or n==1:
        return n
    else:
        return fibonacci(n-1) + fibonacci(n-2)

print(fibonacci(8))





# 3.. TO FIND IF THE GIVEN STRING IS PALINDROME OR NOT

def isPalindrome(strng):
    if len(strng)==0:
        return True
    if strng[0]==strng[-1]:
        return isPalindrome(strng[1:-1])
    
    else:
         return False
print((isPalindrome('naman')))




# 4..TO FIND THE SUM OF ALL DIGITS IN THE GIVEN NUMBER

def sum(n):
    assert n>=0 and int(n)==n , "only positive integers"
    if n==0:
        return 0
    else:
        return int(n%10) + sum(int(n//10))

print(sum(11))




# 5..TO FIND THE POWER OF A NUMBER

def power(base,exp):
    assert exp>=0 and int(exp)==exp , "power can only be positive integers"
    if(exp==0):
        return 1
    if(exp==1):
        return base
    else:
        return base*power(base,exp-1)

print(power(2,5))
