# Csapatok [PROGRAMOZÁS]

Egy osztályba $n$ tanuló jár, akik között $m$ **irányítatlan** (kölcsönös) baráti kapcsolat van.

Döntsd el, hogy szét lehet-e osztani a tanulókat két csapatra úgy, hogy barátok **ne** kerüljenek egy csapatba, és ha igen, adj is meg egy ilyen szétosztást!

## Bemenet

A bemenet első sorában két egész szám, $n$ és $m$ szerepel: a tanulók és a barátságok száma $(2 \le n \le 10^5, 1 \le m \le 2 \cdot 10^5)$. A tanulókat $1,2,\dots,n$ sorszámmal jelöljük.

Ezt követi $m$ sor, amelyek a barátságokat írják le. Minden sor két egész számot, $a$ és $b$ $(1 \le a,b \le n, a \ne b)$ tartalmaz, ami azt jelenti, hogy $a$ és $b$ barátok.

Ugyanazon tanulópár között legfeljebb egy barátság van.

## Kimenet

Ha van megoldás, akkor adj meg egy lehetséges csapatbeosztást, olyan módon, hogy minden tanulóhoz (a sorszámuk szerinti növekvő sorrendben) az $1$ vagy a $2$ számot írod ki, aszerint, hogy melyik csapatba osztottad be őket. Ha több megoldás is lehetséges, bármelyiket megadhatod.

Ha nincs megoldás, az **IMPOSSIBLE** szót kell kiírni.

## Példa

Bemenet:
```
5 3
1 2
1 3
4 5
```

Kimenet:
```
1 2 2 1 2
```