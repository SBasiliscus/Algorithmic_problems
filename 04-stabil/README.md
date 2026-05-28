# Stabil párosítás [PROGRAMOZÁS]

Implementáld az Algoritmikus játékelméletből tanult lánykérő algoritmust!

Adott $n$ fiú és $m$ lány, akik közül néhányan alkothatnak párt egymással. Mindenki preferencia szerint sorba rendezi a potenciális partnereit. Keress egy stabil párosítást!

## Bemenet

A bemenet első sorában az $n$ és $m$ egész számok, a fiúk és a lányok száma $(1 \le n,m \le 2000)$ állnak. A fiúkat $1 \dots n$, a lányokat $1 \dots m$ sorszámozzuk.

Ezt követi $n$ sor, a fiúk preferencialistáinak leírása. Minden sor első száma $k_i$ $(0 \le k_i \le m)$: az $i$. fiú által rangsorolt lányok száma. Ezt követi $k_i$ lánysorszám, preferencia szerint csökkenő sorrendben (legjobb választástól a legrosszabbig).

Ezt követi $m$ sor, a lányok preferencialistáinak leírása, azonos formátumban.

Az élek **irányítatlanok**: ha egy lány szerepel egy fiú rangsorában, a fiú is szerepel a lány rangsorában.

## Kimenet

A kimenet első sorában a stabil párosítás $r$ élszáma áll. Ezt követi $r$ sor, mindegyikben egy pár: a fiú és a lány sorszáma. Ha több stabil párosítás is létezik, bármelyik kiírható.

## Példa

Bemenet:
```
5 5
3 2 3 1
1 3
2 2 4
3 5 4 3
3 1 3 5
2 1 5
2 3 1
4 5 2 1 4
2 3 4
2 5 4
```

Kimenet:
```
4
1 1
3 2
4 5
5 3
```
