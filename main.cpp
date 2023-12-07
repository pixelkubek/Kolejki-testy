#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<assert.h>
#include<iterator>
#include<map>

#include"kol.h"

typedef std::vector< std::vector<interesant*> > listaUrzedu;

std::map<interesant*, int> numerki;

void wyswietlUrzad();

void symNowyInteresant(int kolejka, listaUrzedu &v){
    static int nr = 0;
    interesant *nowyInteresant = nowy_interesant(kolejka);
    numerki.insert({nowyInteresant, nr++});
    v[kolejka].push_back(nowyInteresant);
}

void symObsluz(int kolejka, listaUrzedu &v){
    interesant *obsluzony = obsluz(kolejka);

    if(v[kolejka].empty()) assert(obsluzony == NULL);
    else{
        assert(obsluzony == v[kolejka].front());
        assert(numerek(obsluzony) == numerki[obsluzony]);
        numerki.erase(obsluzony);
        
        std::vector<interesant*> nVector;
        for(size_t i = 1; i < v[kolejka].size(); i++)
            nVector.push_back(v[kolejka][i]);
        v[kolejka] = nVector;

        free(obsluzony);
    }
}

void symZamianaOkienka(int kolejka, int idxInteresanta, int nowaKolejka, listaUrzedu &v){
    std::vector<interesant*>::iterator zamieniajacy = std::next(v[kolejka].begin(), idxInteresanta);
    zmiana_okienka(*zamieniajacy, nowaKolejka);
    v[nowaKolejka].push_back(*zamieniajacy);
    v[kolejka].erase(zamieniajacy);
}

void symZamkniecieOkienka(int kolejka, int nowaKolejka, listaUrzedu &v){
    zamkniecie_okienka(kolejka, nowaKolejka);
    v[nowaKolejka].insert(v[nowaKolejka].end(), v[kolejka].begin(), v[kolejka].end());
    v[kolejka].clear();
}

void symFastTrack(int kolejka, int pierwszy, int drugi, listaUrzedu &v){
    std::vector<interesant*> obsluzeni = fast_track(v[kolejka][pierwszy], v[kolejka][drugi]);
    assert((int)obsluzeni.size() == drugi - pierwszy + 1);
    for(int i = pierwszy; i < drugi + 1; i++){
        assert(obsluzeni[i - pierwszy] == v[kolejka][i]);
        assert(numerek(obsluzeni[i - pierwszy]) == numerki[v[kolejka][i]]);
        numerki.erase(obsluzeni[i - pierwszy]);
        free(obsluzeni[i - pierwszy]);
    }

    std::vector<interesant*> nVector;
    for(int i = 0; i < (int)v[kolejka].size(); i++){
        if(i < pierwszy || i > drugi)
            nVector.push_back(v[kolejka][i]);
    }

    v[kolejka] = nVector;
}

void symNaczelnik(int kolejka, listaUrzedu &v){
    naczelnik(kolejka);
    size_t n = v[kolejka].size();
    for(size_t i = 0; i < n / 2; i++)
        std::swap(v[kolejka][i], v[kolejka][n - i - 1]);
}

void symZamkniecieUrzedu(listaUrzedu &v){
    std::vector<interesant*> obsluzeni = zamkniecie_urzedu();
    int licznik = 0;
    for(std::vector<interesant*> kolejka : v){
        for(interesant* its : kolejka){
            assert(obsluzeni[licznik] == its);
            assert(numerek(obsluzeni[licznik]) == numerki[its]);
            free(obsluzeni[licznik++]);
        }
    }
}


int main(){
    int m, n;
    std::cin >> m >> n;
    listaUrzedu v;

    for(int i = 0; i < m; i++)
        v.push_back({});

    otwarcie_urzedu(m);

    int a, b, c;
    for(int i = 0; i < n; i++){
        char ch;
        std::cin >> ch;
        switch(ch){
        case 'N':
            std::cin >> a;
            symNowyInteresant(a, v);
            break;
        case 'O':
            std::cin >> a;
            symObsluz(a, v);
            break;
        case 'Z':
            std::cin >> a >> b >> c;
            symZamianaOkienka(a, b, c, v);
            break;
        case 'C':
            std::cin >> a >> b;
            symZamkniecieOkienka(a, b, v);
            break;
        case 'F':
            std::cin >> a >> b >> c;
            symFastTrack(a, b, c, v);
            break;
        case 'R':
            std::cin >> a;
            symNaczelnik(a, v);
            break;
        }
    }

    symZamkniecieUrzedu(v);

    return 0;
}