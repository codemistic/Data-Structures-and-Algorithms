def anagram_checker(s1,s2):
    list1 = list(s1)
    list2 = list(s2)

    list1.sort()
    list2.sort()

    pos = 0
    matches = True
    if len(list1) != len(list2):
        return False 

    while pos < len(s1) and matches:
        if list1[pos] == list2[pos]:
            pos = pos + 1
        else:
            matches = False

    return matches

# Example - 
# print(anagram_checker('abcde','edcba'))
