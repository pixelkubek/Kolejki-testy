# WDP_Kolejki_Testy

Należy umieścić pliki kol.cpp i kol.h w folderze. Testy są generowane automatycznie, więc nie gwarantuję, że wyłapią wszystkie błędy. Jeśli ktoś znajdzie jakiś błąd, to będę wdzięczny za kontakt.

### Komenda do uruchomienia
```bash
bash ./test.sh -v <true/false>
```

-v - czy użyć valgrinda

Można też przekazać pliki .in na stdin.

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
### Parametry pliku in
Parametry takie jak 
- możliwa ilość kolejek
- możliwa ilość testów
- szansa danego wydarzenia
  
można ustawić w pliku [gen.py](./gen.py).