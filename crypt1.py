"""
ID: frank.b1
LANG: PYTHON3
TASK: crypt1
"""

# fin = open ("crypt1"+".in", "r")
fout = open ("crypt1"+".out", "w")

def words(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(line.split())
  for i in range (0,len(words)):
    for j in range (0,len(words[i])):
      words[i][j]=int(words[i][j])
  return words

dig=words('crypt1.in')[-1]
print(dig)

num=0
for a in dig:
  if a!=0:
    for b in dig:
      for c in dig:
        for d in dig:
          if d!=0:
            for e in dig:
              f=str(e*((100*a)+(10*b)+(c)))
              l=str(d*((100*a)+(10*b)+(c)))
              t=str(((10*d)+e)*((100*a)+(10*b)+(c)))
              if len(f)==3 and len(l)==3:
                x=True
                for i in f:
                  if int(i) not in dig:
                    x=False
                for i in l:
                  if int(i) not in dig:
                    x=False

                for i in t:
                  if int(i) not in dig:
                    x=False
                if x:
                  num+=1
                  print(a,b,c,d,e)
print(num)


fout.write (str(num) + '\n')
fout.close()