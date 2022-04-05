import sys

"""
ID: frank.b1
LANG: PYTHON3
TASK: milk
"""

# fin = open ("milk"+".in", "r")
fout = open ("milk"+".out", "w")

def words(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(line.split())
  for i in range (0,len(words)):
    if len(words[i])==1:
      words[i]=int(words[i][0])
    else:
      for j in range (0,len(words[i])):
        words[i][j]=int(words[i][j])
  return words

def sort(a):
  def partition(arr, l, h):
    i = (l - 1)
    x = arr[h][0]
    for j in range(l, h):
      if arr[j][0] <= x:
        i = i + 1
        arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[h] = arr[h], arr[i + 1]
    return (i + 1)

  def quickSortIterative(arr, l, h):
    size = h - l + 1
    stack = [0] * (size)
    top = -1
    top = top + 1
    stack[top] = l
    top = top + 1
    stack[top] = h

    while top >= 0:
      h = stack[top]
      top = top - 1
      l = stack[top]
      top = top - 1
      p = partition(arr, l, h)
      if p - 1 > l:
        top = top + 1
        stack[top] = l
        top = top + 1
        stack[top] = p - 1
      if p + 1 < h:
        top = top + 1
        stack[top] = p + 1
        top = top + 1
        stack[top] = h

  if len(a)>0:
    b = []
    b.append(a[0])
    for i in range(1, len(a)):
      if a[i] not in a[0:i]:
        b.append(a[i])
    a = b
    if len(a)>1:
      quickSortIterative(a, 0, len(a) - 1)
  return a

n,m=words('milk.in')[0]
input=sort(words('milk.in')[1:])

c,u,i=0,0,0
while u < n:
  x=min(input[i][1],n-u)
  u += x
  c+=( x * (input[i][0]))
  i+=1

fout.write (str(c) + '\n')
fout.close()
