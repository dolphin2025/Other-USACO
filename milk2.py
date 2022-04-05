"""
ID: frank.b1
LANG: PYTHON3
TASK: milk2
"""
fout = open ('milk2.out', 'w')

def words(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(line.split())

  for j in range (0,len(words)):
    for i in range(0,len(words[j])):
      words[j][i]=int(words[j][i])

  return words

def sort(a):
  def partition(arr, low, high):
    i = (low - 1)
    pivot = arr[high][0]

    for j in range(low, high):
      if arr[j][0] <= pivot:
        i = i + 1
        arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return (i + 1)

  def quickSort(arr, low, high):
    if low < high:
      pi = partition(arr, low, high)
      quickSort(arr, low, pi - 1)
      quickSort(arr, pi + 1, high)

  arr = a
  n = len(arr)
  quickSort(arr, 0, n - 1)
  return arr

input=words('milk2.in')
print(input)
l=int(input[0][0])

input=[l]+sort(input[1:])
print(input)

# go=True
# while go:
#   go=False
#   for i in range (1,len(input)-1):
#     if input[i][0]>input[i+1][0]:
#       cur=input[i]
#       input[i]=input[i+1]
#       input[i+1]=cur
#       go=True



c=[]

c.append(input[1])

for i in input[1:]:
  if i[0]<=c[-1][1]:
    if c[-1][1]<i[1]:
      c[-1][1]=i[1]
  else:
    c.append(i)

cont=[]
idle=[]

for i in range (0,len(c)):
  cont.append(c[i][1]-c[i][0])
for i in range (0,len(c)-1):
  idle.append(c[i+1][0]-c[i][1])

# print(c)

if idle==[]:
  idle.append(0)

# print(cont,idle)

fout.write (str(max(cont))+' '+str(max(idle)) + '\n')
fout.close()