# Egyetem [PROGRAMOZÁS]

Az egyetem adminisztrátoraként $n$ tárgy előkövetelményrendszerét kell ellenőrizned. A tárgyakhoz összesen $m$ **irányított** előkövetelmény tartozik. Egy $a \rightarrow b$ előkövetelmény azt jelenti, hogy a $b$ tárgy megkezdéséhez az $a$-t korábban teljesíteni kell.

Döntsd el, hogy lehetséges-e az összes tárgyat teljesíteni valamilyen sorrendben (félévente egy tárgy elvégzésével), és ha igen, adj meg egy lehetséges teljesítési sorrendet!

## Bemenet

A bemenet első sorában két egész szám, $n$ és $m$ szerepel: a tárgyak és az előkövetelmények száma $(2 \le n \le 10^5, 1 \le m \le 2 \cdot 10^5)$. A tárgyakat $1,2,\dots,n$ sorszámmal jelöljük.

Ezt követi $m$ sor, amelyek az előkövetelményeket írják le. Minden sor két egész számot, $a$ és $b$ $(1 \le a,b \le n, a \ne b)$ tartalmaz, ami azt jelenti, hogy az $a$ tárgyat a $b$ megkezdése előtt teljesíteni kell.

Ugyanazon tárgypár között ugyanabban az irányban legfeljebb egy előkövetelmény van.

## Kimenet

Ha lehetséges, adj meg egy sorrendet, amelyben az összes tárgyat teljesíteni lehet. Ha több megoldás is lehetséges, bármelyiket megadhatod.

Ha nincs megoldás, az **IMPOSSIBLE** szót kell kiírni.

## Példa

Bemenet:
```
5 3
1 2
3 1
4 5
```

Kimenet:
```
3 4 1 5 2
```
