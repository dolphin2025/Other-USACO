"""
ID: frank.b1
LANG: PYTHON3
TASK: friday
"""
t='friday'

fin = open (t+'.in', 'r')
fout = open (t+'.out', 'w')

def DayofWeek(year,month,day):

  days = ['Monday','Tuesday','Wednesday','Thursday','Friday','Saturday','Sunday']
  months = ['January','February','March','April','May','June','July','August','September','October','November','December']
  daysinmonth=[31,28,31,30,31,30,31,31,30,31,30,31]

  # year = int(input('Year: '))
  # month = int(months.index(input('Month: '))+1)
  # day = int(input('Day: '))

  # (year,month,day)=2007,2,13

  # print(year,month,day)

  def leap(year):
    return (year%400==0) or ((year%4==0)and(year%100!=0))

  if leap(year):
    daysinmonth[1]+=1

  dp=0
  for i in range (1899,year):
    if leap(i):
      dp+=366
    else:
      dp+=365

  for i in daysinmonth[0:month-1]:
    dp+=i

  dp+=day
  dp+=5

  return (days[dp%7])

print(DayofWeek(2019,11,26))

n=int(fin.readline()[0:-1])
days = ['Saturday', 'Sunday','Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday']
out=[0,0,0,0,0,0,0]

for year in range (1900,1900+n):
  for month in range (1,13):
    out[days.index(DayofWeek(year,month,13))]+=1

s=''
for i in out:
  s = s+ str(i)+' '


fout.write(s[0:-1] + '\n')
fout.close()