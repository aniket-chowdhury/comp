import sys
sys.setrecursionlimit(10000)

def maxDivisor(n):
    i=2
    if(n==2):
        return 1
    
    while(i<=(n**0.5)):
        if n%i==0:
            return n/i
        i+=1

    return 1

def isPrime(n): 
    if n <= 1: 
        return False  
    for i in range(2, n): 
        if n % i == 0: 
            return False
    return True

def nearestPrime(n):
    if(((n//6)*6+1)<=n):
        return ((n//6)*6)+1
    else:
        return ((n//6)*6)-1

def driver(n):
    if(n<2):
        return 1
    k=nearestPrime(n)

    if(isPrime(k)):
        if(n-k<=2):
            k=driver(k-1)
        return maxDivisor(k)+driver(n-k)
    else: 
        return driver(k-1)

print(driver(int(input())))