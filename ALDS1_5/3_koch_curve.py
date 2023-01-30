import math
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def kock(n,p1,p2):
    
    if n==0:
        return 
    s=Point(0,0)
    t=Point(0,0)
    u=Point(0,0)
    s.x=(2*p1.x+1*p2.x)/3
    s.y=(2*p1.y+1*p2.y)/3
    t.x=(1*p1.x+2*p2.x)/3
    t.y=(1*p1.y+2*p2.y)/3
    u.x=(t.x-s.x)*math.cos(math.pi/3)-(t.y-s.y)*math.sin(math.pi/3)+s.x
    u.y=(t.x-s.x)*math.sin(math.pi/3)+(t.y-s.y)*math.cos(math.pi/3)+s.y
    kock(n-1,p1,s)
    print(s.x,s.y)
    kock(n-1, s, u)
    print(u.x,u.y)
    kock(n-1, u, t)
    print(t.x,t.y)
    kock(n-1, t, p2)



n= int(input())
p1=Point(0,0)
print(p1.x,p1.y)
p2=Point(100,0)
kock(n,p1,p2)
print(p2.x,p2.y)
