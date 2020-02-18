def findLargest(l, n): 
    l.sort() 
    divisors = [1 for i in range(n)] 
    previous = [-1 for i in range(n)] 

    maximum = 0
 
    for i in range(1,n):
        for j in range(i): 
            if (l[i] % l[j] == 0): 
                if (divisors[i] < divisors[j] + 1): 
                    
                    divisors[i] = divisors[j]+1
                    previous[i] = j 

        if (divisors[maximum] < divisors[i]): 
            maximum = i 

    k = maximum 
    while (k >= 0): 
        print(l[k],end = " ") 
        k = previous[k] 

n = int(input())
l = list(map(int,input().spli   t()))
findLargest(l, n)