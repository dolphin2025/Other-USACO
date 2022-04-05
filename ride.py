"""
ID: frank.b1
LANG: PYTHON3
TASK: ride
"""

def makenum(str):
  n = 1
  for character in str:
    n *= int(['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'].index(character)+1)
  return n
open ('ride.out', 'w').write (['STAY','GO'][(makenum(open ('ride.in', 'r').readline()[0:-1])%47)==(makenum(open ('ride.in', 'r').readlines()[1][0:-1])%47)] + '\n')
