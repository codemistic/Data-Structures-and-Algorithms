n = int(input())
l = list( map(int,input().split()))
j = 0
i = 0
a = max(l)
max_index = l.index(max(l))
for i in range(0,n-1):
    if  l[i] < l[i+1] :
        j = j+1
    else :
        break
for i in range(i,n-1) :
    if  l[i] == l[i+1] :
        j = j+1
    else :
        break
for i in range(i,n-1) :
    if  l[i] > l[i+1] :
        j = j+1
    else :
        break
if j == n-1 :
    print("YES")
else :
    print("NO")
