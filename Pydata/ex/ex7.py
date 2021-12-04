
for i in range(100,1000):
    n=str(i)
    sum=0
    for j in n:
        j=int(j)
        sum+=j**3

    if sum==int(n):
        print(n)
    i+=1
 