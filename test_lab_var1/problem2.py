def read(path) :
    harta = {}
    with open(path, 'r') as file:
        nume_echipa = ""
        for line in file:
            if line[:6] == 'Echipa' :
                nume_echipa = line[7:].strip()
                harta[nume_echipa] = {}
            else:
                harta[nume_echipa][line[:line.find(':')-1]] = line[line.find(':')+1:].split()
    return harta

def premianti(map, *arr, k) :
    rezultat = []
    for echipa in map:
        for membru in map[echipa]:
            scoruri = sorted([int(x) for x in map[echipa][membru]])
            tokenMembru=[echipa, membru]
            premiat = []
            medie = 0
            for scor in scoruri:
                if scor in arr:
                    premiat.append(scor)
                    medie += scor
            if(len(premiat) > k) :
                tokenMembru.append(premiat)
                tokenMembru.append(round(float(medie/len(premiat)), 2))
                rezultat.append(tokenMembru)
    rezultat = sorted(rezultat, key=lambda x: x[:-1], reverse=True)
    return rezultat
def stergere (map, nume_echipa, nume_membru):
    del map[nume_echipa][nume_membru]
    if(len(map[nume_echipa]) > 1):
        return map[nume_echipa]
    else :
        for nume in map[nume_echipa].keys():
            mesaj = "Am sters si jucatorul " + str(nume) + " si echipa " + str(nume_echipa) 
        del map[nume_echipa]

        return mesaj

path = r"Z:\GitHub\Homework\test_lab_var1\punctaje.in"
echipe = read(path)
premiati = premianti(echipe, 50, 25, 40, 60, 30, 45, k=3 )

print(stergere(echipe, "Potiuni magice", "Strumfita"))
print(stergere(echipe, "Potiuni magice", "Papa Strumf"))