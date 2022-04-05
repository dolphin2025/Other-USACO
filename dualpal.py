"""
ID: frank.b1
LANG: PYTHON3
TASK: dualpal
"""

def BC(n,b1,b2):
  num1 = str(n)
  base1 = b1
  base2 = b2

  digitList = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
               'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
  decimal = 0
  for i in range(0, len(num1)):
    decimal = decimal + int(digitList.index(num1[i])) * (base1 ** (len(num1) - i - 1))

  n = ''
  i = 1
  x = True
  while x:
    y = (decimal % (base2 ** i)) // (base2 ** (i - 1))
    # print(digitList[y])
    if (base2 ** (i - 1)) > decimal:
      x = False
    else:
      n += digitList[y]
    i += 1

  n = n[::-1]

  return n

fin = open ("dualpal"+".in", "r")
fout = open ("dualpal"+".out", "w")
n,s=fin.readline().split()
n,s=int(n),int(s)
nums=[]

i=s+1
while len(nums)<n:
  c=0
  for b in range (2,11):
    print(i,b,BC(i,10,b))
    if BC(i,10,b)==BC(i,10,b)[::-1]:
      c+=1
  if c>1:
    nums.append(i)
  i+=1

print(nums)

for j in nums:
  fout.write(str(j) + '\n')
fout.close()
