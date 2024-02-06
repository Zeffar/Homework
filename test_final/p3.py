# two pointers, O(N)

n = int(input())
v = [int(x) for x in input().split()]
rez = 0
left = 0
for right in range (1, n):
    if(v[right] < v[right-1]):
        rez = max(rez, right-left)
        left=right
print(rez)
    