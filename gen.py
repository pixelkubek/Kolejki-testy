from random import randint, seed
from sys import argv

seed(int(argv[1]))

M = randint(2, 20)      #ilosc kolejek
N = randint(10, 100)    #ilosc wydarzen


f = open("dane.in", "w")

urzad = [-1] * M
print(f'{M} {N}', file=f)

def nowyInteresant():
    kol = randint(0, M - 1)
    urzad[kol] += 1
    print(f'N {kol}', file=f)
    return True

def obsluz():
    kol = randint(0, M - 1)
    print(f"O {kol}", file=f)
    urzad[kol] -= 1
    return True

def zamianaOkienka():
    kol = randint(0, M - 1)
    if urzad[kol] < 0:
        return False
    
    interesant = randint(0, urzad[kol])
    nextKol = randint(0, M - 1)
    while(kol == nextKol):
        nextKol = randint(0, M - 1)
    print(f'Z {kol} {interesant} {nextKol}', file=f)
    urzad[kol] -= 1
    return True

def zamkniecieOkienka():
    kol = randint(0, M - 1)
    nextKol = randint(0, M - 1)
    while kol == nextKol:
        nextKol = randint(0, M - 1)
    print(f'C {kol} {nextKol}', file=f)
    urzad[kol] = -1
    return True

def fastTrack():
    kol = randint(0, M - 1)
    if urzad[kol] < 0:
        return False
    pierwszy = randint(0, urzad[kol])
    drugi = randint(pierwszy, urzad[kol])
    print(f'F {kol} {pierwszy} {drugi}', file=f)
    urzad[kol] = urzad[kol] - (drugi - pierwszy + 1)
    return True

def naczelnik():
    print(f'R {randint(0, M - 1)}', file=f)
    return True

#szanse na wydarzenia
wagi = {
    nowyInteresant : 10,
    obsluz : 7,
    zamianaOkienka : 1,
    zamkniecieOkienka : 1, 
    fastTrack : 1,
    naczelnik : 1
}

sumaWag = 0

zasiegi = list(wagi.values()).copy()

for i in range(len(wagi)):
    sumaWag += zasiegi[i]
    zasiegi[i] = (sumaWag - zasiegi[i],  sumaWag - 1)

wagi = dict(zip(wagi.keys(), zasiegi))

i = 0
while i < N:
    los = randint(0, sumaWag - 1)
    for fun, wag in wagi.items():
        if wag[0] <= los <= wag[1] :
            i += fun()

f.close()