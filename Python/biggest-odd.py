
"""Create a function called biggest_odd that takes a string of numbers
and returns the biggest odd number in the list. For example, if you
pass ‘23569’ as an argument, your function should return 9. Use list
comprehension"""


def biggest_odd(num_list):
    numbers = [int(x) for x in num_list ]
    return max([ n for n in numbers if n % 2 != 0])
     


    
if __name__ == "__main__":
    print(biggest_odd("126598142"))