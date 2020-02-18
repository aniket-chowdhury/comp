def addEdge(l,u,v):
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
# print(l)