# FIFA [GUROBI]

A **FIFA** elemzési csapata összegyűjtötte a 2006-2022 közötti öt világbajnokság összes büntetőpárbajának adatait. Minden egyes rúgásnál rögzítették, hogy a rúgó a kapu melyik zónájába célzott, a kapus melyik zónába mozdult, és hogy gól született-e. A kaput 3 zónára osztjuk a rúgó szemszögéből: **bal**, **közép** és **jobb**.

A feladat meghatározni a **minimax stratégiát** mind a rúgó, mind a kapus számára. A játék $G$ mátrixa egy 3x3-mas mátrix, melynek sorai a rúgó három stratégiáját, oszlopai pedig a kapus három stratégiáját reprezentálják és a sorjátékos szemszögéből adják meg a kifizetéseket, a következőképpen: a mátrix $G_{ij}$ cellája a gól empirikus valószínűségét tartalmazza, ha a rúgó az $i$. zónába rúg és a kapus a $j$. zónába mozdul.

Ez egy zéróösszegű kétszemélyes stratégiai játék: a rúgó maximalizálja a gól valószínűségét, a kapus minimalizálja. Mindkét fél egyszerre dönt: a rúgó nem tudja előre, merre ugrik a kapus, és fordítva.

## Bemenet

A `fifa.csv` fájl tartalmazza a büntetőrúgások statisztikáit:

| Oszlop | Leírás |
|--------|--------|
| `ev` | A világbajnokság éve |
| `rugo` | A rúgó neve |
| `kapus` | A kapus neve |
| `rugo_zona` | A rúgó célzóna: `bal`, `kozep`, `jobb` |
| `kapus_zona` | A kapus mozgásiránya: `bal`, `kozep`, `jobb` |
| `gol` | `1` ha gól született, `0` ha nem |

Az adatok a valóságnak csak részben felelnek meg. Ha valaki ügyesebb nálam és el tudja készíteni a valódi adatok pontos táblázatát, lekötelez, ha megosztja velem! :)

## Kimenet

A feladatot Gurobival kell megoldani, az elkészített `*.py` és a `kimenet.txt` fájlokat kell feltölteni.

A [`kimenet.txt`](./kimenet.txt) fájl tartalma:

```
Kifizetési mátrix (sorok: rúgó zóna, oszlopok: kapus zóna):
             bal   kozep    jobb
bal            ?       ?       ?
kozep          ?       ?       ?
jobb           ?       ?       ?

Rúgó minimax stratégiája:
- P(bal)=?
- P(kozep)=?
- P(jobb)=?
Biztonsági szint (gól valószínűség alsó korlát): 0.455

Kapus minimax stratégiája:
- P(bal)=?
- P(kozep)=?
- P(jobb)=?
Biztonsági szint (gól valószínűség felső korlát): 0.455
```

A program feladata ugyanebben a formátumban kiírni a választ, a kérdőjelek helyén a tényleges adatokkal.

A rúgó és a kapus biztonsági szintjeit megadtam, melyek Neumann minimax tétele (illetve a később felfedezett LP dualitás) értelmében egyenlőek.

## Mese

A minimax tételt **John von Neumann** bizonyította 1928-ban, ez az egyik alapköve a játékelméletnek. Az LP-dualitással való kapcsolatot **George Dantzig** (a szimplex módszer atyja) fedezte fel: a minimax tétel és az LP erős dualitása ekvivalens állítások.

**Ignacio Palacios-Huerta** közgazdász 2003-ban (*"Professionals Play Minimax"*, American Economic Review) empirikusan megvizsgálta, hogy a profi focisták tényleg minimax stratégiát játszanak-e büntetőknél. Az eredmény: igen, a megfigyelt stratégiafrekvenciák statisztikailag nem különböznek a jóslattól.
