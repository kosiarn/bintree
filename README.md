# bintree

Implementacja drzewa binarnego w języku C++.
Realizacja projektu z przedmiotu Algorytmy i Struktury danych.

Kod implementuje strukturę węzła drzewa, która zawiera:

- wartość liczbową typu Integer,
- wskaźniki do lewego i prawego dziecka,
- metody:
    - operacji na węzłach:
        - wstawianie,
        - usuwanie
    - obliczanie:
        - głębokości struktury,
        - ilości węzłów
    - wyświetlania struktury

Funkcja `main()` zawiera przykładowe zastosowanie struktury.

## Ścieżka

jest to łańcuch znaków składający się z dowolnej ilości liter `r` oraz `l`.

Przykład: Przejście przez ścieżkę `lrl` poprowadzi w poniższym drzewie:

```
|__5
    |--2
    |   |--3
    |   |   |--4
    |   |   |   |--1
    |   |   |__9
    |   |__1
    |       |--6
    |       |__0
    |__8
        |--1
        |__2
```
(Gdzie węzeł górny to węzeł lewy) do węzła z wartością 6.

Format ścieżki używany jest w metodzie `insert()` jako jeden z parametrów, a w metodzie `treeLookup()` jako zwracana wartość.

# Struktura drzewa binarnego

Drzewo binarne to graf, w którym każdy węzeł połączony jest z jednym albo dwoma innymi węzłami w sposób nietworzący pętli. Ze względu na chierarchiczność tej struktury, implementacja algorytmów operujących na niej można ułatwić stosując rekurencję. Metody operujące na drzewie binarnym zaimplementowane są w każdym węźle, dlatego część operacji można oddelegować od rodzica do jego dziecka. Większość zaimplementowanych metod korzysta z tego podejścia, wywołując tę samą metodę w węzłach-dzieciach, aby wykonanie zacząć od liści drzewa.