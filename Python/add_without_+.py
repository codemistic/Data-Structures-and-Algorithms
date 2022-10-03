def Bitwise_add(a,b):
    while b != 0:
        carry = a&b # Carry value is calculated 
        a = a^b # Sum value is calculated and stored in a
        b = carry<<1 # The carry value is shifted towards left by a bit

    return a # returns the final sum
