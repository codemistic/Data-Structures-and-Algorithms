# permutation

def per(list1,list2):
    list1.sort()
    list2.sort()
    if list1==list2:
                return "permutation"
    return "not"

print(per([1,2,3,5],[5,2,1,3]))
print(per(['a','c','e','d'],['d','c','a','e']))

