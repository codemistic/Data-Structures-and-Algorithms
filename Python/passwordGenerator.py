import random
import string

def generate_password(length, include_upper, include_digits, include_special):
    """
    Generate a secure password based on user preferences.
    
    Parameters:
    - length: int, the total length of the password.
    - include_upper: bool, whether to include uppercase letters.
    - include_digits: bool, whether to include digits.
    - include_special: bool, whether to include special characters.
    
    Returns:
    - str: Generated password.
    """
    if length < 4:
        return "Password length must be at least 4 characters for security."

    lower = string.ascii_lowercase
    upper = string.ascii_uppercase if include_upper else ""
    digits = string.digits if include_digits else ""
    special = string.punctuation if include_special else ""

    # Ensure password has at least one character from each selected group
    mandatory_chars = (
        random.choice(lower) +
        (random.choice(upper) if include_upper else "") +
        (random.choice(digits) if include_digits else "") +
        (random.choice(special) if include_special else "")
    )

    # Fill the rest of the password length with a random mix of the selected groups
    all_chars = lower + upper + digits + special
    if len(all_chars) < 1:
        return "Please select at least one character type."
    
    remaining_length = length - len(mandatory_chars)
    random_chars = "".join(random.choices(all_chars, k=remaining_length))

    # Combine mandatory and random characters, then shuffle to randomize order
    password = list(mandatory_chars + random_chars)
    random.shuffle(password)
    return "".join(password)

# User interaction
print("Welcome to the Advanced Password Generator!")
try:
    length = int(input("Enter the desired length of your password (minimum 4): "))
    include_upper = input("Include uppercase letters? (y/n): ").strip().lower() == 'y'
    include_digits = input("Include digits? (y/n): ").strip().lower() == 'y'
    include_special = input("Include special characters? (y/n): ").strip().lower() == 'y'
    
    password = generate_password(length, include_upper, include_digits, include_special)
    print(f"Your secure password is: {password}")
except ValueError:
    print("Invalid input. Please enter a valid number for the password length.")
