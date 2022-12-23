#ユークリッドの互除方

x,y=map(int,input().split())
if y>=x:
    a=y
    y=x
    x=a
while 1:
    a=x%y
    if a==0:break
    x=y
    y=a
print(y)