#バブルソート
def bu(A,N):
    flag=1
    c=0
    N-=1
    m=N
    while flag:
        N=m
        flag=0
        while N>=1:
            j=N
            if A[j]<A[j-1]:
                a=A[j]
                A[j]=A[j-1]
                A[j-1]=a
                flag=1
                c+=1
            N-=1
    print(*A)
    return c

n=int(input())
lst=list(map(int,input().split()))
a=bu(lst,n)
print(a)