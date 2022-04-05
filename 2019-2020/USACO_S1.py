
n=int(open ('moobuzz.in', "r").readline())
open('moobuzz.out', "w").write(str(15*(n//8)+[-1,1,2,4,7,8,11,13][n%8]) + '\n')