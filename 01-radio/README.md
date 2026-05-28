# Rádió [PROGRAMOZÁS]

A bemeneten adott egy rádióállomás adott napi lejátszási listája. A lista $n$ hosszú, minden zeneszámot egy pozitív egész szám azonosít. A listában ugyanaz a zeneszám többször is szerepelhet.

Mi az a leghosszabb intervallum hossza, ahol minden zeneszám egyedi a listában?

## Bemenet

A bemenet első sorában az $n$, a lejátszási lista hossza áll ($1 \le n \le 2 \cdot 10^5$).

A következő sorban $n$ darab egész szám szerepel: $k_1,k_2,\ldots,k_n$, az egyes dalok azonosítószáma, $1 \le k_i \le 10^9$.

## Kimenet

A kimenet egyetlen sorból áll: azon leghosszabb intervallum hossza, amin minden zeneszám egyedi volt.

## Példa

Bemenet:
```
8
1 2 1 3 2 7 4 2
```

Kimenet:
```
5
```

Magyarázat:

Az `1 3 2 7 4` intervallum $5$ hosszú, ennél hosszabb pedig nincs.
