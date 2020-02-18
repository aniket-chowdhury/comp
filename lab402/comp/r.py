inp = list(map(int,input().split()))

x=inp[0]
y=inp[1]
count = 0

if(y==x):
    print(0)

elif(y%x==0):
    k=y/x
    while(k):
        if(k%2==0):
            k/=2
            count+=1
        if(k%3==0):
            k/=3
            count+=1
        else:
            break
    if(k==1):
        print(count)

else:
    print(-1)