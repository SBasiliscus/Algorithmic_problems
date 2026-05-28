# Boldogtalanság [PROGRAMOZÁS]

Folytasd a [01-stabil](../01-stabil) feladatot a következőképpen!

Tanultuk, hogy a lánykérő algoritmussal megtalálhatjuk a fiú-optimális és a lány-optimális stabil párosítást, illetve hogy adott preferenciák mellett a stabil párosítások ugyanazt a csúcshalmazt fedik le.

Definiáljuk egy fiú boldogtalanságát a következőképpen: ha az $i$. fiú a fiú-optimális stabil párosításban az ő preferencialistája szerint az $f_i$. lányt kapta, egy tetszőleges stabil párosításban pedig az $x$.-et, akkor legyen az ő boldogtalansága a tetszőleges stabil párosításban $x - f_i$, ahol $f_i \le x$. Ha az $i$. fiú nincs fedve a stabil párosítások által, akkor a boldogtalanságát nem értelmezzük.

A lányok boldogtalanságát hasonlóan definiáljuk.

Számítsd ki minden résztvevőre a maximális lehetséges boldogtalanságot: a fiúkét a lány-optimális (azaz fiú-pesszimális), a lányokét a fiú-optimális (azaz lány-pesszimális) stabil párosításra nézve!

## Bemenet

A bemenet formátuma és méretei egyeznek a [01-stabil](../01-stabil) feladattal!

## Kimenet

A kimenet első $n$ sora a fiúk boldogtalanságát adja meg: az $i$. sorban az $i$. fiú boldogtalansága áll. A következő $m$ sorban a lányoké következik: az $n+i$. sorban az $i$. lány boldogtalansága áll. A stabil párosítások által nem fedett résztvevőkre $-1$-et írj ki!

## Példa

Az alábbi gráfot azért raktam be, mert Algojátékon láttuk (példa több stabil párosítással rendelkező gráfra). Ez éppen egy teljes páros gráf, de van olyan teszteset is, ami **nem az**!

Bemenet:
```
3 3
3 3 1 2
3 1 2 3
3 2 3 1
3 3 1 2
3 1 2 3
3 2 3 1
```

Kimenet:
```
2
2
2
2
2
2
```
