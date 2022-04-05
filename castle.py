"""
ID: frank.b1
LANG: PYTHON3
TASK: castle
"""

global castle

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

walls={}

def invoke(col,row):
    global c
    global walls
    print(col,row)
    if c[col][row]==1:
        return [0,[]]
    else:
        c[col][row]=1
        r=[1,[]]
        val=castle[row][col]
        # print(val,col,row)
        if val>=8:
            val-=8
            if row<n-1:
                # print('row',row)
                wall=[col,row+1,'N']
                # if wall==[0,1,'N']:
                #     print(col,row)
                r[1].append(wall)
        else:
            if  c[col][row+1]==0:
                invo=invoke(col,row+1)
                r[0]+=invo[0]
                r[1]+=invo[1]
        if val>=4:
            val-=4
            wall=[col,row,'E']
            walls[tuple(wall)]=0
            r[1].append(wall)
        else:
            if  c[col+1][row]==0:
                invo=invoke(col+1,row)
                r[0]+=invo[0]
                r[1]+=invo[1]
        if val>=2:
            val-=2
            wall=[col,row,'N']
            # if wall==[0,1,'N']:
            #     print(col,row)
            walls[tuple(wall)]=0
            r[1].append(wall)
        else:
            if c[col][row-1]==0:
                invo=invoke(col,row-1)
                r[0]+=invo[0]
                r[1]+=invo[1]
        if val>=1:
            val-=1
            if col>0:
                wall=[col-1,row,'E']
                r[1].append(wall)
        else:
            if  c[col-1][row]==0:
                invo=invoke(col-1,row)
                r[0]+=invo[0]
                r[1]+=invo[1]
        # print(r)
        return r



def countRooms():
    global c
    # This uses flood fill algorithm to count rooms and room sizes
    rs=[]
    c=[]
    for i in range (0,m):
        x=[]
        for j in range (0,n):
            x.append(0)
        c.append(x)
    # print(c)
    for col in range (0,m):
        for row in range (0,n):
            if c[col][row]==0:
                x=(invoke(col,row))
                x[1]=list(list(i) for i in list({tuple(i) for i in x[1]}))
                rs.append(x)
                # print(x)
    return len(rs),max(rs, key=lambda i: i[0])[0],rs


def bestwall(rs,walls):
    global c
    wn=0
    for r in rs:
        for wall in r[1]:
            walls[tuple(wall)]+=r[0]
    bestwall=[(m+1,0,'N'),0]
    for i in walls:
        if walls[i]>bestwall[1]:
            bestwall=[i,walls[i]]
        elif walls[i]==bestwall[1]:
            if i[0]<bestwall[0][0]:
                bestwall = [i, walls[i]]
            elif i[0]==bestwall[0][0]:
                if i[1]>bestwall[0][1]:
                    bestwall = [i, walls[i]]
                elif i[1]==bestwall[0][1] and i[2]=='N':
                    bestwall = [i, walls[i]]
    return bestwall



if __name__ == "__main__":

    ans = ''

    # fin = open ("castle"+".in", "r")
    fout = open("castle" + ".out", "w")

    input = intwords('castle.in')
    m, n = input[0]
    castle = input[1:]

    # print(castle)


    r1 = countRooms()
    ans += str(r1[0])
    ans += '\n'
    ans += str(r1[1])
    ans += '\n'
    rs=r1[2]
    # print(ans)
    print('wa',walls)
    print(rs)

    bestwall = bestwall(rs,walls)



    # print(w)
    ans+=str(bestwall[1])
    ans+='\n'
    ans+=str(bestwall[0][1]+1)
    ans+=' '
    ans+=str(bestwall[0][0]+1)
    ans+=' '
    ans+=str(bestwall[0][2])

    fout.write (ans + '\n')
    fout.close()

