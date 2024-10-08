#Prime-Number checker
'''
Prime Number: A number that is divisible only by itself and 1 
(e.g. 2, 3, 5, 7, 11).
'''
def is_prime(n):
  for i in range(2,n):
    if n%i==0:
      return False
  return True
n=int(input("Enter the number to check for Prime "))
if is_prime(n):
  print("Given number is a prime number")
else:
  print("Given number is not a prime number")
'''
In: Enter the number to check for Prime 3
Op: Given number is a prime number

In:Enter the number to check for Prime 9
Op:Given number is not a prime number
'''
