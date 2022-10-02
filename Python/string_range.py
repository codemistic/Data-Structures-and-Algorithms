'''Write a function called string_range that takes a single number and
returns a string of its range. The string characters should be
separated by dots(.) For example, if you pass 6 as an argument,
your function should return ‘0.1.2.3.4.5’.'''


def string_range(number):
    _string = ""
    for num in range(0, number):
        _string += str(num)+"."   # loop over every element in the range, convert it to a string and concatenate it to the _string variable which is initialized initialy as an empty string 
    return _string[0:len(_string)-1] # to remove the last "." from our return value :) 

    
       
if __name__ == "__main__":
    print(string_range(45))