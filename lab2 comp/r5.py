'''def addEdge(l,u,v):
    l[u].append(v)
    l[u] = list(dict.fromkeys(l[u]))
    l[v].append(u)
    l[v] = list(dict.fromkeys(l[v]))



inp = list(map(int,input().split()))
# inp = [1, 2, 3, 4, 1, 5]
l=[[]for i in range(len(inp))]

for i in range(len(inp)-1):
    n=len(inp)
    if(i==0):
        addEdge(l,0,1)
    else:
        addEdge(l,i,i+1)

pos = [[]for i in range(10)]
for i in range(len(inp)):
    pos[inp[i]].append(i)

for i in pos:
    if(len(i)>1):
        for k in i:
            for j in i:
                if(j!=k):
                   addEdge(l,i[0],i[1])


import sys
pred = [-1 for i in range(len(inp))]
dist = [sys.maxsize for i in range(len(inp))]

def BFS(l,src,dest,v):
    queue = []
    visited = [False for i in range((v))]

    visited[src]=True
    dist[src]=0

    queue.append(src)

    while (len(queue)!=0): 
        u = queue[0] 
        queue.pop(0)
        for i in range(len(l[u])):  
            if (visited[l[u][i]] == False) :
                visited[l[u][i]] = True
                dist[l[u][i]] = dist[u] + 1 
                pred[l[u][i]] = u
                queue.append(l[u][i])
  
                if (l[u][i] == dest):
                   return True 
        


def shortestDistance(l,src,dest,v):

    BFS(l, src, dest, v)
    path=[]

    crawl=dest

    path.append(crawl)
    while(pred[crawl]!=-1):
        path.append(pred[crawl])
        crawl=pred[crawl]
    return len(path)-1
    

    

print(shortestDistance(l,0,len(inp)-1,len(inp)))
# print(l)'''
from collections import deque 
N = 100005
  
gr = [[] for i in range(N)] 
  
def add_edge(u, v): 
    gr[u].append(v) 
    gr[v].append(u) 
  
def dijkstra(n): 
    vis = [0 for i in range(n)] 
    dist = [10**9 for i in range(n)] 
  
    vis[0] = 1
    dist[0] = 0
    q = deque() 
    q.append(0) 
    while (len(q) > 0): 
        x = q.popleft() 
        for i in gr[x]: 
  
            if (vis[i] == 1): 
                continue
            vis[i] = 1
  
            dist[i] = dist[x] + 1
  
            q.append(i) 
  
    return dist[n - 1] 
  
def Min_Moves(a, n): 
  
    fre = [[] for i in range(10)] 
    for i in range(n): 
        if (i != n - 1): 
            add_edge(i, i + 1) 
  
        fre[a[i]].append(i) 
  
    for i in range(10): 
        for j in range(len(fre[i])): 
            for k in range(j + 1,len(fre[i])): 
                if (fre[i][j] + 1 != fre[i][k] and 
                    fre[i][j] - 1 != fre[i][k]): 
                    add_edge(fre[i][j], fre[i][k]) 
  
    return dijkstra(n) 
  
inp = list(map(int,input().split()))
a = inp 
n = len(a) 
  
print(Min_Moves(a, n)) 