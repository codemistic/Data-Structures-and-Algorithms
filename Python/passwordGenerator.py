import random
import string
print("Welcome to the Password Generator!")
total = string.ascii_letters + string.digits + string.punctuation
length = int(input("How many characters would you like in your password? "))
password = "".join(random.sample(total, length))
print(f"Your secure password is: {password}")
