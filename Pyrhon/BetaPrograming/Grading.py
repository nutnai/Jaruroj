a = int(input())
b = int(input())
c = int(input())
z = a+b+c
if z >= 80:
    print("A")
elif z >= 75:
    print("B+")
elif z >= 70:
    print("B")
elif z >= 65:
    print("C+")
elif z >= 60:
    print("C")
elif z >= 55:
    print("D+")
elif z>= 50:
    print("D")
else: 
    print("F")
