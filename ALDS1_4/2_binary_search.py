n=int(input())
s=list(map(int,input().split()))
q=int(input())
t=list(map(int,input().split()))
left = 0
right = n
count=0
for key in t:
    left = 0
    right = n
    while left < right:
        mid = (left + right) / 2
        mid=int(mid)
        if s[mid] == key:
            count+=1
            break
        elif key < s[mid]:
            right = mid
        else:
            left = mid + 1
print(count)