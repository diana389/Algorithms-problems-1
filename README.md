# PA - TEMA 1 - APROAPE FARA GIGEL -
### Stefan Diana Maria - 322CC

## FERIBOT
Am facut un `binary search` pentru a determina costul minim pentru care toate masinile se incadreaza in cele k feriborturi. 

Complexitate temporala: `O(N * log sum)`, unde sum este suma elementelor din vector. (PossibleResult - O(N), BinarySearch - O(N * log sum))

## NOSTORY
- `task1`: 
Am pus elementele din ambii vectori in unul singur care a fost sortat descrescator si am facut suma primelor n elemente. Acesta este scorul maxim.

Complexitate: `O(n * log n)` - qsort.
- `task2`: 
Am observat ca cea mai buna mutare pentru a maximiza scorul este interschimbarea celui mai mic maxim si cel mai mare minim, cat timp primul este mai mic decat al doilea. La fiecare mutare, suma se mareste cu diferenta dintre cele doua.

Complexitate temporala: `O(n * log n)` - qsort.

## SUSHI
- `task1`:
Rezolvarea este similara cu cea a `problemei rucsacului` din laborator.

Complexitate temporala: `O(m * n * x)`.

- `task2`: 
Fiecare farfuri este privita ca doua farfurii identice distincte, dublandu-se valorile din vectorii de preturi si de note.

Complexitate temporala: `O(m * n * x)`.

- `task3`: 
Exista o structura `plate` care contine nota si pretul unei farfurii si un vector ce contine toate farfuriile, sortat descrescator dupa note.
Exista si o structura pentru elementele din matrice, care contine valoarea normala si, in plus, numarul de farfurii adaugate pana in acel moment. In momentul in care  numarul de farfurii a ajuns la n, nu se mai adauga o noua farfurie. In rest, rezolvarea este asemanatoare cu cea din subpunctele anterioare.

Complexitate temporala: `O(m * n * x)`.

## SEMNALE
- `type1`:
Am construit o matrice in care liniile corespund numarului de 1 si coloanele numarului de 0. Se fixeaza 0 sau 10 pe primele pozitii si se continua recurenta.

Complexitate temporala: `O(x * y)`.

- `type2`:
Este o rezolvare similara celei de la type1, doar ca de aceasta daca exita 3 cazuri (0, 10, 110).

Complexitate temporala: `O(x * y)`.

## BADGPT
Numarul de siruri initiale provine din produsul numarul subsirurilor initiale posibila la intalnirea literelor 'n' sau 'u'.

### Recurenta ar fi: 
    // n - numarul de litere

    // pe prima pozitie se afla 'n' / 'u' => se fixeaza primea litera
    nr_subsiruri(n) = nr_subsiruri(n - 1);

    // pe prima pozitie se afla 'm' / 'w' => se fixeaza primele 2 litere
    nr_subsiruri(n) += nr_subsiruri(n - 2);

Am observat ca acest sir este similar sirului `fibonacci`, insa decalat cu o pozitie, deci rezultatul este termenul `n + 1` al sirului fibonacci.
Acest termen se poate afla ridicand la putere matricea `[[1 1] [1 0]]`.

Complexitate temporala: `O(m * log n)`, unde m este numarul de perechi (litera - numar) citite (multiply - O(1), power - O(log n), substring - O(log n), task - O(m * log n)).
