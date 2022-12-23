#素数かの見極め関数
def isprime(x):
    if x == 2:
        return True

    if x < 2 or x%2==0:
        return False

    i = 3
    while (i <= x**0.5):
        if x%i==0:
            return False
        i = i + 2

    return True


n=int(input())
c=0
for i in range(n):
    N=int(input())
    a=isprime(N)
    if a==True:
        c+=1
print(c)