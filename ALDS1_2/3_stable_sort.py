#バブルソート
def BubbleSort(A,N):
    flag=1
    c=0
    N-=1
    m=N
    while flag:
        N=m
        flag=0
        while N>=1:
            j=N
            if int(A[j][1])<int(A[j-1][1]):
                a=A[j]
                A[j]=A[j-1]
                A[j-1]=a
                flag=1
            N-=1
    print(*A)
    print('Stable')
#選択ソート
def SelectionSort(l,n):
    for i in range(n):
        minj=i
        for j in range(i,n):
            if l[j][1]<l[minj][1]:
                minj=j
        a=l[i]
        l[i]=l[minj]
        l[minj]=a
    print(*l)
#安定なソートか調べる
def isStable(s, out,N):#sは入力の配列、outはソート後の配列
    for i in range(N):
        for j in range(i+1,N):
            for a in range(N):
                for b in range(a+1,N):
                    if s[i][1] == s[j][1]  and s[i] == out[b] and s[j] == out[a]:
                        return False
    return True

n=int(input())
lst=list(input().split())
#値渡しみたいにするための配列のコピー
A=[]
B=[]
for i in lst:
    A.append(i)
for i in lst:
    B.append(i)
BubbleSort(lst,n)
SelectionSort(A,n)
if isStable(B,A,n):
    print("Stable")
else:
    print("Not stable")