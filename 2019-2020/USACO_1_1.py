
# fin = open ('gymnastics.in', "r")
fout = open('gymnastics.out', "w")


def words(file):
    words = []
    with open(file) as f:
        lines = f.readlines()
        for line in lines:
            words.append(line.split())
    for i in range(0, len(words)):
        for j in range(0, len(words[i])):
            words[i][j] = int(words[i][j])
    return words


[k, n] = words('gymnastics.in')[0]
input = words('gymnastics.in')[1:]
print(n, k, input)

counter = 0

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i != j:
            x = True
            for rank in input:
                if rank.index(i) > rank.index(j):
                    x = False
            if x:
                counter += 1
                print(i, j)

fout.write(str(counter) + '\n')
fout.close()
