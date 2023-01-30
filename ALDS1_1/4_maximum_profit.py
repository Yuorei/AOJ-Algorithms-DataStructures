n=int(input())
R=[0 for i in range(n)]
for i in range(n):
    R[i]=int(input())
minv=R[0]
maxv=R[1]-R[0]
for j in range(1,n):
    if R[j]-minv>maxv:
        maxv=R[j]-minv
    if minv>R[j]:
        minv=R[j]
print(maxv)