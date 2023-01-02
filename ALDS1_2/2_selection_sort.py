n = int(input())
l = list(map(int,input().split()))
c=0
for i in range(n):
    minj=i
    for j in range(i,n):
        if l[j]<l[minj]:
            minj=j

    a=l[i]
    l[i]=l[minj]
    l[minj]=a
    if l[i]!=l[minj]:
        c+=1
print(*l)
print(c)

