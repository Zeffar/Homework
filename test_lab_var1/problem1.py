import math 
def citire_matrice (path) :
    mat = []
    with open(path, 'r') as file:
        n = int(file.readline().strip())
        n = int(math.sqrt(n))
        for i in range (n):
            mat.append([int(file.readline().strip()) for _ in range (n)])
    return mat

def prelucrare_matrice(a) :
    n = len(a)
    for i in range (n) :
        val = a[i][i]
        for j in range(n):
            a[i][j] -= val
        del(a[i][i])
    return(a)

path = r"Z:\GitHub\Homework\test_lab_var1\fisier.txt"
mat = citire_matrice(path)
# matPrelucrat = prelucrare_matrice(mat)
# for s in matPrelucrat:
#     print(*s)
k = int(input())
canPrint=0
nbs = {}

for line in mat:
    for nb in line:
        # print(nb, sep=' ')
        aux = int(nb)
        rez = 0
        while (aux > 0) :
            rez += aux%10
            aux = int(aux/10)
        # print(rez)
        if rez == k :
            nbs[nb] = 1

sorted_numbers = sorted(nbs)
with open("test_lab_var1/numere.out", 'w') as file:
    for nb in sorted_numbers:
        file.write(str(nb)+' ')

