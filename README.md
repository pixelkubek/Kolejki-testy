# WDP_Kolejki_Testy

Należy umieścić pliki kol.cpp i kol.h w folderze.

### Komenda do uruchomienia
```bash
bash ./test.sh
```

Można też przekazać pliki .in na stdin

### Struktura pliku .in
```
m n //m - liczba kolejek, n - liczba akcji (linijek bez tej)
N 0 //nowy interesant na 0 kolejkę
O 0 //obsłuż 0 kolejkę
Z 0 5 1 //zamień okienko 5 interesanta w 0 kolejce na 1 kolejkę
C 0 3 //zamknij kolejkę 0, nowa kolejka 3
F 1 3 5 //fast-track od 3 interesanta w 1 kolejce do 5 interesanta włącznie
R 1 //naczelnik na kolejce 1
```
