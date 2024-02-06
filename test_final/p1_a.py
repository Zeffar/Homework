def isPrime(x):
    for i in range(2, x):
        if x%i == 0:
            return 0 
    return 1

def divizori(*nb):
    myDict = {}
    for number in nb:
        myDict[number]=[]
        for i in range (2, number):
            if number%i == 0 and isPrime(i):
                myDict[number].append(i)
    return myDict

print(divizori(50, 21))
