import sys
name = 'cowjump'
sys.stdin = open(name+'.in', 'r')
# sys.stdout = open(name+'.out', 'w')

def eval(p, q, x):
    s = (p[1]-q[1])/(p[0]-q[0])
    return s*(x-p[0])+p[1]

def onSegment(p, q, r):
    return (q[0] <= max(p[0], r[0]) and q[0] >= min(p[0], r[0]) and q[1] <= max(p[1], r[1]) and q[1] >= min(p[1], r[1]))

def orientation(p, q, r):
    val = (float(q[1] - p[1]) * (r[0] - q[0])) - (float(q[0] - p[0]) * (r[1] - q[1]))
    if (val < 0): return 2
    return val > 0

def doIntersect(p1, q1, p2, q2):
    o1, o2, o3, o4 = orientation(p1, q1, p2), orientation(p1, q1, q2), orientation(p2, q2, p1), orientation(p2, q2, q1)
    return (o1 != o2) and (o3 != o4) or (o1 == 0) and onSegment(p1, p2, q1) or (o2 == 0) and onSegment(p1, q2, q1) or \
           (o3 == 0) and onSegment(p2, p1, q2) or (o4 == 0) and onSegment(p2, q1, q2)

xs = set()
segs = []
n = int(input())
for i in range (n):
    seg = [int(i) for i in input().split()]
    segs.append(seg)
    xs.add(seg[0])
    xs.add(seg[1])
xs=list(xs)
xs.sort()
print(xs)
print(segs)