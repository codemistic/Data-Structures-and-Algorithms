#Linear Search Program
def linear_search(l,key):
  for i in l:
    if i==key:
      return i
  return -1
l=[1,5,2,7,3]
k=2
f=linear_search(l,k)
if f!=-1:
  print("Key element is at %d index"%f)
else:
  print("Element not found")
#if k=(any number which is not in the list)
#Output: Element not found
#Otherwise it prints "Key element is at {index of that element in list} index"
