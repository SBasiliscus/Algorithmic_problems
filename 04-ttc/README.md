# Top Trading Cycle [PROGRAMOZÁS]

Implementáld az Algoritmikus játékelméletből tanult Top Trading Cycle (TTC) algoritmust lakáspiaci újraosztáshoz!

Adott $n$ résztvevő, mindegyiküknek van egy lakása, és mindenki preferencia szerint sorba rendezi az összes lakást. Számítsd ki, ki melyik lakást kapja a TTC algoritmus szerint!

## Bemenet

A bemenet első sorában egy egész szám, az $n$, a résztvevők száma $(1 \le n \le 2000)$. A résztvevőket $1 \dots n$ sorszámozzuk.

Ezt követi $n$ sor, a résztvevők preferencialistáinak leírása. Az $i$. sor az $1 \dots n$ számok egy permutációja: az $i$. résztvevő preferencia szerint csökkenő sorrendbe rendezett lakássorszámai (legjobb választástól a legrosszabbig).

## Kimenet

A kimenet $n$ sorból áll. Az $i$. sorban az $i$. résztvevő által megkapott lakás eredeti tulajdonosának sorszáma áll.

## Példa

Bemenet:
```
5
3 2 4 1 5
4 3 1 2 5
2 4 5 1 3
2 5 4 3 1
4 1 3 5 2
```

Kimenet:
```
3
4
5
2
1
```
