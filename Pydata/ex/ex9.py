lst1=[1,2,80,66,3,4,7.2,7.23,7.20,5]
lst2=['helloo','ls',90,100]
lst3=[8.1,' ',90,'',' ',1,True]

print(lst1,id(lst1))
lst1.sort()
print(lst1,id(lst1))

lst=sorted(lst1)
print(lst,id(lst))

