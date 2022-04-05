def intwords(file):
  words = []
  with open(file) as f:
    lines = f.readlines()
    for line in lines:
      words.append(line.split())
  for i in range (0,len(words)):
    for j in range (0,len(words[i])):
      words[i][j]=int(words[i][j])
  return words

a=intwords('cereal.in')[1:]
n=len(a)

ans=[[0,{}] for i in a]

ans[-1]=[1,{a[-1][0]}]


for i in range (len(a)-2,-1,-1):
    if a[i][0] not in ans[i+1][1]:
        ans[i]=[ans[i+1][0]+1,ans[i+1][1].union({a[i][0]})]
    elif a[i][1] not in ans[i+1][1]:
        ans[i]=[ans[i+1][0]+1,ans[i+1][1].union({a[i][1]})]
    else:
        ans[i] = [ans[i + 1][0], ans[i + 1][1]]

# print(n,a,ans)

fans=''
for i in ans:
    fans+=str(i[0])+'\n'

open('cereal.out','w').write(fans)