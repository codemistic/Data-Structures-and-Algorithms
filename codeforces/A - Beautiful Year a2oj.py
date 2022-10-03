#https://codeforces.com/problemset/problem/271/A
n =int(input())
k =n+1 
while(True):
    st=str(k)
    s=set(st)
    if len(s)==4:
        break
    k+=1
print(k)
