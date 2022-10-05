# finding the first recurring character in a list using a hashtable
def func(mylist):

    for i in range(0, len(mylist)):
        for j in range(i+1, len(mylist)):
            if mylist[i] == mylist[j]:
                return mylist[i]
    return 0


def hashtable(mylist):
    mydict = {}
    for i in range(0, len(mylist)):
        if mylist[i] in mydict:
            return mylist[i]
        else:
            mydict[mylist[i]] = i
    return 0


mylist = [2, 3, 54, 55, 2, 90, 34, 3, 54]
x = hashtable(mylist)
print(x)
