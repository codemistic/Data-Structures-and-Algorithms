'''
The product of an integer and all the integers below it is known as factorial
e.g. factorial four ( 4! ) is equal to 24.

n! = n*(n-1)*...*1

'''
def fact(n):
  if n==1:
    return 1
  else:
    return n*fact(n-1)
n=int(input("Enter the number "))
f=fact(n)
print("Factorial of {} is {}".format(n,f))
