"""
ID: frank.b1
LANG: PYTHON3
TASK: palsquare
"""
fin = open ('palsquare.in', 'r')
fout = open ('palsquare.out', 'w')

b=int(fin.readline()[0:-1])

def BC(n,b1,b2):
  #input from user-----------------------------------------------------------------

  num1 = str(n)
  base1 = b1
  base2 = b2

  #convert the number to a decimal-------------------------------------------------
  digitList = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
               'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
  decimal = 0
  for i in range(0,len(num1)):
    decimal = decimal + int(digitList.index(num1[i]))*(base1**(len(num1)-i-1))

  n = ''
  i = 1
  x = True
  while x:
    y = decimal % (base2 ** i) // (base2 ** (i - 1))
    if (base2**(i-1))>decimal:
      x = False
    else:
      n += digitList[y]
    i += 1

  n = n[::-1]

  # print(str(n))
  return str(n)

num=[]
for n in range (1,301):
  if BC(n**2,10,b)==BC(n**2,10,b)[::-1]:
    num.append(n)

for i in num:
  if i != ' ':
    fout.write (str(BC(i,10,b))+' ' +str(BC(i**2,10,b))+ '\n')
fout.close()