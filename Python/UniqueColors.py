def minimumColors(n,s,v,i,j,count):
    l=len(v)
    ma=max(v)
    if j>=l:
        print(count-1)
        return
    if v[0]==min(v) and v[l-1]==max(v) and  v[l-1] - v[0] < s:
        print('1')
    #print(i,j,v[i],v[j]) 
    while v[j]-v[i]>=s and v[j+1]-v[i]<s:
        #print(j)
        j=j+1
    
    count=count+1
    i=j
    j=i+1
    minimumColors(n,s,v,i,j,count)
n,s=[int(x) for x in input().split()]
v=[int(i) for i in input().split()]
i=0
j=1
count=0
minimumColors(n,s,v,i,j,count)
