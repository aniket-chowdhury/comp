y=int(input())
x=list(map(int,(input().split())))
# x=[1, 2, 7, 8, 2, 3, 2, 3]
# y=2

def freq(l): 

    f = {} 
    for item in l: 
        if (item in f): 
            f[item] += 1
        else: 
            f[item] = 1

    return list(f.values())

print(len(freq(x))-y)