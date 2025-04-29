s = [] 
while True:
    a = int(input()) 
    if a == 0:  
        break
    if int(str(a),'7') % 10 == 4: 
        s.append(a)

print(s)