# Paritás

Adott egy n hosszú tömb: $a_1, a_2, \dots, a_n$. Egy művelet során megcserélhetsz két tetszőleges, **azonos paritású** $a_i$ és $a_j$ tömbelemet. Az elemeknek nem kell feltétlenül egymás mellett állniuk.

A feladatod eldönteni, hogy a tömb rendezhető-e nemcsökkenő sorrendbe tetszőlegesen sok ilyen művelet segítségével.

## Bemenet

A bemenet első sorában a tömb mérete, $n$ található ($1 \leq n \leq 2 \cdot 10^5$).

A bemenet második sorában a tömb elemei $a_1, \dots, a_n$ vannak felsorolva ($1 \leq a_i \leq 10^9$).

## Kimenet

A kimenet egyetlen sorába az IGEN szót kell írni ha teljesül a feltétel a megadott tömbre, egyébként pedig a NEM szót.

## Példák

1. példa:

Bemenet:
```
5
7 10 1 3 2
```

Kimenet:
```
IGEN
```

2. példa:

Bemenet:
```
5
11 3 15 3 2
```

Kimenet:
```
NEM
```
