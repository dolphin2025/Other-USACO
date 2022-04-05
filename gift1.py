"""
ID: frank.b1
LANG: PYTHON3
TASK: gift1
"""
# fin = open ('gift1.in', 'r')
fout = open ('gift1.out', 'w')

def words(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(line.split())
  return words

input=words('gift1.in')

# print(input)

np=int(input[0][0])

names=[]
m=[]

for i in range (1,np+1):
  names.append(input[i][0])

for i in names:
  m.append(0)

p=np+1

while p<len(input)-1:
  name=input[p][0]
  amount=int(input[p+1][0])
  #print(input[p+1][0])
  give=int(input[p+1][1])
  #print(name,amount,give)
  if give!=0:
    giveto=[]
    for i in range (p+2,p+give+2):
      giveto.append(input[i][0])
    #print(giveto)
    perperson=amount//give
    leftover=amount%give
    for i in giveto:
      m[names.index(i)] += perperson
    m[names.index(name)] += (leftover-amount)
  #print(m)
  p+= (give+2)

for i in names:
  fout.write (i + ' ' + str(m[names.index(i)]) + '\n')
fout.close()