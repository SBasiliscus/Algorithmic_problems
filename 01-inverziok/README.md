# Inverziók számolása [PROGRAMOZÁS]

Adott egy n hosszú tömb: $a_1, a_2, \dots, a_n$. Készítsünk programot ami megmondja a tömb inverziószámát, vagyis azon $a_i$ és $a_j$ párok számát, amelyre $i<j$ és $a_i>a_j$ teljesül.

## Bemenet

A bemenet első sorában az $n$, a számok darabszáma áll $(1 \leq n \leq 2 \cdot 10^5)$.

A második sorban az $a_1, \dots, a_n$ számok állnak $(1 \leq a_i \leq 10^9)$.

## Kimenet

A kimenet egyetlen sorában az inverziók száma álljon.

## Példa

### 1\. példa

Bemenet:
```
5
5 4 3 2 1
```

Kimenet:
```
10
```

### 2\. példa

Bemenet:
```
5
5 1 2 3 4
```

Kimenet:
```
4
```

### 3\. példa

Bemenet:
```
4
4 2 1 3
```

Kimenet:
```
4
```
