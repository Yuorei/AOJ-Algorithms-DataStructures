def partition(A,p,r):
    x=A[r]
    i=p-1
    for j in range(p,r):
        if A[j]<=x:
            i+=1
            a=A[i]
            A[i]=A[j]
            A[j]=a
    a=A[i+1]
    A[i+1]=A[r]
    A[r]=a
    return i+1

n=int(input())
l=list(map(int,input().split()))
q=partition(l, 0, n-1)
l[q]=[l[q]]
print(*l)
