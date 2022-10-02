"""Write a function called odd_even that has one parameter
and takes a list of numbers as an argument. The function
returns the difference between the largest even number in
the list and the smallest odd number in the list. For example,
if you pass [1,2,4,6] as an argument the function should
return 6 -1= 5."""


def odd_even(param):
    odds = [x for x in param if x % 2 != 0 ]
    evens = [ y for y in param if y %2 == 0]

    return (sorted(evens, reverse=True)[0] - sorted(odds)[0]) 
    
    #return max(evens) - min(odds)  <---- Alternative method

if __name__ == "__main__":
    print(odd_even([4,4,52,5,6,1,2,7,89,45,15221,4,265,1235,26,21,54,3,15,78,53,26,32,458,8]))
    print(odd_even([1,2,4,6]))
   