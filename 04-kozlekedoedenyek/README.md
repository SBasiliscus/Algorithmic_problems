# Közlekedőedények [PROGRAMOZÁS]

Implementáld az Algoritmikus játékelméletből tanult Kaminski-féle közlekedőedény-rendszert a kelmeszabály-konzisztens szétosztásra a nem-hidraulikus számítógépünkön! :)

A feladat érdekessé tétele érdekében ugyanazon követelésrendszerre több kérdés is érkezik, különböző szétosztandó vagyonértékekre: minden kérdésnél csak a **legnagyobb** kiosztott vagyonmennyiséget kell megadni.

## Bemenet

A bemenet első sorában az $n$ és $q$ egész számok, a követelések és a kérdések száma $(1 \le n,q \le 2 \cdot 10^5)$ állnak.

Ezt követi $n$ sor, a követelések értékei: az $i$. sorban a $k_i$ páros egész szám az $i$. hitelező követelése $(2 \le k_i \le 2000)$.

Végül $q$ sor következik a kérdésekkel: az $i$. sorban a $v_i$ szétosztandó vagyonmennyiség $(0 \le v_i \le 10^4)$.

## Kimenet

A kimenet $q$ sorból áll. Az $i$. sorban a $v_i$ vagyonmennyiség esetén a ksz-konzisztens szétosztás **legnagyobb** részesedése áll, tizedestört alakban, $10^{-6}$-os pontossággal.

## Példa

Bemenet:
```
4 3
6
4
8
2
2
4
5
```

Kimenet:
```
0.500000
1.000000
1.333333
```
