# Épülő város [PROGRAMOZÁS]

Egy képzeletbeli ország $n$ városa között $m$ kétirányú autóút szakasz van. Sajnos az útszakaszok szörnyű állapotban vannak, ezért használhatatlanok. A kormány úgy döntött, hogy megjavít néhány útszakaszt úgy, hogy bármely városból bármely városba el lehessen jutni autóúton.

Minden útszakaszról lehet tudni mennyibe kerül megjavítani. A te feladatod megadni a felújításhoz szükséges minimális költséget.

## Bemenet

A bemenet első sorában az $n$ és $m$ egész számok találhatók: a városok és útszakaszok darabszámai. A városokat $1,2,\dots,n$ sorszámozzuk. $1 \le n \le 10^5$, $1 \le m \le 2 \cdot 10^5$.

Ezt követi $m$ sor, az egyes útszakaszok leírásai. Az $i$. sorban az $a_i$, $b_i$ és $c_i$ egész számok találhatók: ekkor van egy útszakasz az $a_i$. és a $b_i$. város között, melynek a felújítási költsége $c_i$. $1 \le a_i,b_i \le n$, $1 \le c_i \le 10^9$.

Minden útszakasz két különböző várost köt össze és minden várospárt legfeljebb egy útszakasz köt össze.

## Kimenet

A kimenet egyetlen sorában egy egész szám legyen, a lehetséges minimális költség.

Előfordulhat, hogy nincs megoldás, ilyenkor az **IMPOSSIBLE** szót kell kiírni.

## Példa

Bemenet:
```
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
```

Kimenet:
```
14
```
