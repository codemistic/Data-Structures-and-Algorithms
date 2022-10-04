# Largest number from the given/entered three numbers


# Taking the input from the user 
num1 = float(input("Enter the first number - "))
num2 = float(input("Enter the second number - "))
num3 = float(input("Enter the third number - "))

#if, elif, else blocks
if(num1 >= num2) and (num1 >= num3):
   largest = num1
elif(num2 >= num3) and (num2 >= num1):
   largest = num2
else: 
   largest = num3

print("The largest number is", largest)   