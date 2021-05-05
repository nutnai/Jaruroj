n = int(input())
minn = 2000000000
maxx = int(−2000000000)

for i in range(n):
    z = int(input())
    minn = min(minn,z)
    maxx = max(maxx,z)
print(minn)
print(maxx)
