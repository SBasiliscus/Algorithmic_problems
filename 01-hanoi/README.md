# Hanoi tornyai [PROGRAMOZÁS]

![](./hanoi.png)

A Hanoi tornyai játék három (bal, középső és jobb) rúdból és $n$ darab különböző méretű kerek korongból áll. Kezdetben a bal rúdon van az összes korong, méretük szerint növekvő sorrendben, felülről lefelé haladva.

A cél az, hogy az összes korongot a jobb rúdra helyezzük. Megengedett lépés az egyik rúdról a legfelső korong egy másik rúdra áthelyezése, viszont nagyobb korongot kisebb korong tetejére nem szabad rakni.

A feladat a minimális lépésszámú megoldás megtalálása és ezen lépésszám, illetve a mozgatási instrukciók kiírása a kimenetre.

## Bemenet

Az egyetlen bemeneti sorban egy egész szám van, $n$ a lemezek száma, $1 \le n \le 16$.

## Kimenet

Az első sorba a $k$-t, a minimális mozgatások számát kell kiírni.

A rákövetkező $k$ sor mindegyikében egy lépés leírása legyen, vagyis egy $a$ és egy $b$ egész szám, ami azt jelenti, hogy az $a$. rúd aktuális felső korongját a $b$. rúdra mozgatjuk. A rudak sorszámozása: $1$=bal, $2$=középső, $3$=jobb.

## Példák

Bemenet:
```
2
```

Kimenet:
```
3
1 2
1 3
2 3
```
