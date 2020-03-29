mainlist = []
infile = open('Names.txt','r+')
for line in infile:
    mainlist.append(line)
infile.close()

term = -1
new_name = input("Enter the name you want to add: ") 
new_name=new_name+'\n'
for p in mainlist:
    if(str(p) == str(new_name)):
        term=-1
        break
    if(p > new_name):
        break
    term=term+1

if(term == (-1)):
    print('Name already exist!!!')
else:
    temp = []
    infile = open('Names.txt','w')
    infile.truncate(0)
    infile.close()
    for i in range(0,term+1):
        temp.append(str(mainlist[i]))
    temp.append(str(new_name))
    for i in range(term+1,len(mainlist)):
        temp.append(str(mainlist[i]))
    infile = open('Names.txt','a')
    for i in temp:
        infile.write(str(i))
    infile.close()
    print('File Updated')
        
