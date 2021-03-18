import math

def coprimo(num):
    for out2 in range(2,num):
        if math.gcd(num,out2) == 1:
            return out2

quant = int(input("Quantos numeros primos?"))

p = []
for i in range(quant):
    p.append(int(input()))
print(p)

N = 1
for i in range(len(p)):
    N *= p[i]

print("N = ", N)

fiN = 1
for i in range(len(p)):
    fiN *= p[i] - 1

print("fiN = ", fiN)
 
e = coprimo(fiN)
print("e = ", e)

d = pow(e,-1,fiN)
print("d = ", d)

C = pow(int(input("insira a mensagem:")),e)%N
print("C = ", C)

dn = []
for i in range(len(p)):
    dn.append(d % (p[i] - 1))
print("dn = ",dn)

Mn = []
for i in range(len(p)):
    Mn.append((pow(C,dn[i],p[i])))
print("Mn = ",Mn)

x = 0
for i in range(len(p)):
    x += int(Mn[i]) * int(N / p[i]) * pow(int(N / p[i]), -1,int(p[i]))
x = x % N

print(x)