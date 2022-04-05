
inp = open('citystate.in').readlines()

n = inp[0][:-1]
cities = set()
for line in inp[1:]:
    city, state = line.split()
    if city[:2] != state:
        cities.add((city[:2],state,))

ans = 0
for (city, state) in cities:
    if (state, city) in cities and city != state:
        ans += 1


open('citystate.out', 'w').write(str(ans//2))