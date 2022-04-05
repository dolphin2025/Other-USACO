
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

def inter(s1,s2):
    try:
        v1=(((s1[0]-s1[2])/(s1[1]-s1[3]))*(s1[0]-s2[0])+s1[1])
        v2=(((s1[0]-s1[2])/(s1[1]-s1[3]))*(s1[0]-s2[2])+s1[1])
        return (v1>s2[1] and v2<s2[3]) or  (v1<s2[1] and v2>s2[3])
    except:
        temp=s1[0]
        s1[0]=s1[1]
        s1[1]=temp
        temp=s1[2]
        s1[2]=s1[3]
        s1[3]=temp
        temp=s2[0]
        s2[0]=s2[1]
        s2[1]=temp
        temp=s2[2]
        s2[2]=s2[3]
        s2[3]=temp

        v1=(((s1[0]-s1[2])/(s1[1]-s1[3]))*(s1[0]-s2[0])+s1[1])
        v2=(((s1[0]-s1[2])/(s1[1]-s1[3]))*(s1[0]-s2[2])+s1[1])
        return (v1>s2[1] and v2<s2[3]) or  (v1<s2[1] and v2>s2[3])
l=words('cowjump.in')[1:]
print(l)

for i in range (0,len(l)):
    for j in range (i+1,len(l)):
        print(l[i],l[j])
        print(inter(l[i],l[j]))