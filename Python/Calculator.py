
# Python program for simple calculator
 
# Function to add two numbers 

def add(num1, num2):

    return num1 + num2
 
# Function to subtract two numbers 

def subtract(num1, num2):

    return num1 - num2
 
# Function to multiply two numbers

def multiply(num1, num2):

    return num1 * num2
 
# Function to divide two numbers

def divide(num1, num2):

    return num1 / num2

# Function to return the remainder of the division operation

def modulus(num1, num2):

    return num1 % num2

# Function to return the nearest quotient of the division operation

def floor(num1, num2):

    return num1 // num 2


print("Please select operation -\n" \

        "1. Add\n" \

        "2. Subtract\n" \

        "3. Multiply\n" \

        "4. Divide\n" \
        
        "5. Remainder" \
        
        "6. Quotient")
 
 
# Take input from the user 

select = int(input("Select operations from 1, 2, 3, 4, 5, 6 :"))


number_1 = int(input("Enter first number: "))

number_2 = int(input("Enter second number: "))
 
# The user has selected addition
if select == 1:

    print(number_1, "+", number_2, "=",

                    add(number_1, number_2))
 
# The user has selected subtraction
elif select == 2:

    print(number_1, "-", number_2, "=",

                    subtract(number_1, number_2))
 
# The user has selected multiplication
elif select == 3:

    print(number_1, "*", number_2, "=",

                    multiply(number_1, number_2))
 
# The user has selected division
elif select == 4:

    print(number_1, "/", number_2, "=",

                    divide(number_1, number_2))

# The user has selected the modulo operator
elif select == 5:

    print(number_1, "%", number_2, "=", modulus(number_1, number_2))

# The user has selected the floor division operator
elif select == 6:

    print(number_1, "//", number_2, "=", floor(number_1, number_2))

# The user has entered a number that is not in the list
else:

    print("Invalid operation. Please retry.")
