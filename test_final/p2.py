# used input file for practice
# sort O(N log N) + walkthrough O(N) = O(N log N)
with open ("input.txt") as read:
    n = int(read.readline())
    S = []
    for line in read:
        S.append(line.split())
        
    S = sorted(S, key = lambda x : x[1])
    cnt = 0
    lastShow = 0
    for show in S:
        if int(show[0]) >= lastShow:
            lastShow = int(show[1])
            cnt += 1
    print(cnt)