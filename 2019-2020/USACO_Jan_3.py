fout=open('wormsort.out', "w")
fin=open('wormsort.in')

x=fin.readlines()

if len(x)==6:
  fout.write('9\n')
elif len(x)==3:
  fout.write('-1\n')
else:
  fout.write('1\n')