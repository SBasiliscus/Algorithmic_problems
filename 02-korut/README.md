# Körút [PROGRAMOZÁS]

Egy országban $n$ város található, amelyek között $m$ buszjárat közlekedik. A buszjáratok **irányítottak**: egy $a \rightarrow b$ buszjárattal csak $a$-ból $b$-be lehet eljutni, visszafelé nem.

Tervezz körutazást: indulj egy tetszőleges városból, látogass meg legalább egy másik várost, majd térj vissza a kezdővárosba! A kezdővárosba teleportálással kerülsz be (valahogy), busszal pedig minden városba pontosan
egyszer érkezhetsz meg. Döntsd el, hogy létezik-e ilyen, **tetszőleges hosszú** körút, és ha igen, adj is meg egyet!

## Bemenet

A bemenet első sorában két egész szám, $n$ és $m$ szerepel: a városok és a buszjáratok száma $(2 \le n \le 10^5, 1 \le m \le 2 \cdot 10^5)$. A városokat $1,2,\dots,n$ sorszámmal jelöljük.

Ezt követi $m$ sor, amelyek a buszjáratokat írják le. Minden sor két egész számot, $a$ és $b$ $(1 \le a,b \le n, a \ne b)$ tartalmaz, ami azt jelenti, hogy van egy buszjárat az $a$ városból a $b$ városba.

Ugyanazon várospár között ugyanabban az irányban legfeljebb egy buszjárat közlekedik.

## Kimenet

Ha létezik körutazás, a kimenet első sorában a $k$ szám szerepeljen, amely a kiírt városok száma. A második sorban add meg a körútvonalat a városok sorszámaival: az első és az utolsó szám ugyanaz (a kezdőváros sorszáma). Ha több megoldás is létezik, bármelyik (tetszőleges hosszú) megadható.

Ha nem létezik körutazás, az **IMPOSSIBLE** szót kell kiírni.

## Példa

Bemenet:
```
5 6
1 3
1 2
3 5
5 1
2 4
4 5
```

Kimenet:
```
4
3 5 1 3
```
