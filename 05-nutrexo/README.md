# Nutrexo [GUROBI]

A **Nutrexo** intézményi étkeztetési vállalat kórházak, irodák és iskolák büféjét látja el napi étkezéssel. A cég egyik legfontosabb célja, hogy a napi étkezési költséget minimalizálja, miközben betartja az EU által előírt tápanyagbeviteli ajánlásokat.

Adott $n$ db alapanyag, mindegyikhez ismert **100g-onként** az ára és a tápanyagtartalma. Határozd meg, hogy naponta melyik alapanyagból hány grammot kell felhasználni, hogy a napi étkezési költség minimális legyen, miközben az alábbi tápanyagbeviteli követelmények teljesülnek (az EU által előírt napi referencia-értékek alapján):

| Tápanyag     | Minimum    | Maximum   |
|--------------|------------|-----------|
| Kalória      | 1800 kcal  | 2200 kcal |
| Fehérje      | 50 g       | -         |
| Zsír         | 20 g       | 70 g      |
| Szénhidrát   | 260 g      | -         |
| Rost         | 25 g       | -         |
| C-vitamin    | 80 mg      | -         |
| A-vitamin    | 800 µg     | -         |
| Kalcium      | 800 mg     | -         |

Bónusz feladat: felhasználási javaslat (receptek)! :)

## Bemenet

A `nutrexo.csv` fájl tartalmazza az alapanyagok adatait, az értékek 100 g-ra vonatkoznak:

| Oszlop | Leírás |
|--------|--------|
| `nev` | Az alapanyag neve |
| `kcal` | Energiatartalom (kcal) |
| `feherje_g` | Fehérje (g) |
| `zsir_g` | Zsír (g) |
| `szenhidrat_g` | Szénhidrát (g) |
| `rost_g` | Rost (g) |
| `vitamin_c_mg` | C-vitamin (mg) |
| `vitamin_a_ug` | A-vitamin (µg) |
| `kalcium_mg` | Kalcium (mg) |
| `ar_Ft` | Ár (Ft) |

Az adatok a valóságnak csak részben felelnek meg. Ha valaki ügyesebb nálam és el tudja készíteni a valódi adatok pontos táblázatát, lekötelez, ha megosztja velem! :)

## Kimenet

A feladatot Gurobival kell megoldani, az elkészített `*.py` és a `kimenet.txt` fájlokat kell feltölteni.

A [`kimenet.txt`](./kimenet.txt) fájl tartalma:

```
Optimális napi költség: 908.05 Ft

Szükséges alapanyagok (név, g):

- ?: ? g

Összesített tápanyagtartalom:

- Kalória:     ? kcal
- Fehérje:     ? g
- Zsír:        ? g
- Szénhidrát:  ? g
- Rost:        ? g
- C-vitamin:   ? mg
- A-vitamin:   ? µg
- Kalcium:     ? mg

Bónusz: Felhasználási javaslat, receptek

?
```

A program feladata ugyanebben a formátumban kiírni a választ, a kérdőjelek helyén a tényleges adatokkal.

A szükséges alapanyagok egy felsorolás, annyi gondolatjellel ahány alapanyag az optimális megoldásban szerepel. Az étrend összesített tápanyagtartalma teljesíti a feladatban megadott EU-s előírásokat.

Az optimális napi költséget megsúgtam, a többi adatot kell kitölteni.

## Mese

Egy híres LP feladat, a diéta probléma (diet problem). George Stigler közgazdász fogalmazta meg 1945-ben, eredeti kontextusában egy amerikai katona minimális költségű, de tápanyagszükségleteit kielégítő napi étrendjét kereste. Stigler kézzel közelítette meg az optimumot, az általa kapott étrend évi ~39,93 dollárba került (1939-es árakon). Néhány évvel később, George Dantzig szimplex módszerével megoldva kiderült, hogy az igazi optimum évi ~39,67 dollár, azaz Stigler közelítése mindössze 24 centtel tért el. Stigler 1982-ben közgazdasági Nobel-díjat kapott, igaz, más munkásságáért. Talán nem meglepő, hogy az optimális étrend akkor is és most is döbbenetesen egyhangú.