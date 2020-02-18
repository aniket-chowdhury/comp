import random

x=[random.randint(-40,40) for i in range(20)]
y=[random.randint(-40,40) for i in range(20)]

t = [(x[i],y[i]) for i in range(20)]

print(sorted(t))