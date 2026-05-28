# Lejárt licensz esetén gyorssegély:
# import os
# os.environ['GRB_LICENSE_FILE'] = ''

import csv
import gurobipy as gp
from gurobipy import GRB

alapanyagok = []
with open("nutrexo.csv", newline="", encoding="utf-8") as f:
  reader = csv.DictReader(f)
  for row in reader:
    alapanyagok.append({
      "nev": row["nev"],
      "kcal": float(row["kcal"]),
      "feherje_g": float(row["feherje_g"]),
      "zsir_g": float(row["zsir_g"]),
      "szenhidrat_g": float(row["szenhidrat_g"]),
      "rost_g": float(row["rost_g"]),
      "vitamin_c_mg": float(row["vitamin_c_mg"]),
      "vitamin_a_ug": float(row["vitamin_a_ug"]),
      "kalcium_mg": float(row["kalcium_mg"]),
      "ar_Ft": float(row["ar_Ft"]),
    })

m = gp.Model(f"nutrexo")
  ## m.Params.NonConvex = 2
x = m.addVars(len(alapanyagok), lb=0, vtype=GRB.CONTINUOUS, name = 'x') #létrehoztam annyi x változót amennyi alapanyag van: x1, x2, ...



m.addConstr(gp.quicksum(x[i]*alapanyagok[i]["kcal"] for i in range(len(alapanyagok))) >= 1800)
m.addConstr(gp.quicksum(x[i]*alapanyagok[i]["kcal"] for i in range(len(alapanyagok))) <= 2200)
m.addConstr(gp.quicksum(x[i]*alapanyagok[i]["feherje_g"] for i in range(len(alapanyagok))) >= 50)
m.addConstr(gp.quicksum(x[i]*alapanyagok[i]["zsir_g"] for i in range(len(alapanyagok))) >= 20)
m.addConstr(gp.quicksum(x[i]*alapanyagok[i]["zsir_g"] for i in range(len(alapanyagok))) <= 70)
m.addConstr(gp.quicksum(x[i]*alapanyagok[i]["szenhidrat_g"] for i in range(len(alapanyagok))) >= 260)
m.addConstr(gp.quicksum(x[i]*alapanyagok[i]["rost_g"] for i in range(len(alapanyagok))) >= 25)
m.addConstr(gp.quicksum(x[i]*alapanyagok[i]["vitamin_c_mg"] for i in range(len(alapanyagok))) >= 80)
m.addConstr(gp.quicksum(x[i]*alapanyagok[i]["vitamin_a_ug"] for i in range(len(alapanyagok))) >= 800)
m.addConstr(gp.quicksum(x[i]*alapanyagok[i]["kalcium_mg"] for i in range(len(alapanyagok))) >= 800)

m.setObjective(gp.quicksum(x[i]*alapanyagok[i]["ar_Ft"] for i in range(len(alapanyagok))), GRB.MINIMIZE)
m.optimize()

  #av, bv, cv = int(a.X), int(b.X), int(c.X)
T = m.ObjVal
  #ki(f"min_kerulet={feladat['min_kerulet']}: a={av}, b={bv}, c={cv}, terulet={T}")
with open("kimenet.txt", "w", encoding="utf-8") as out:
  out.write(f"Optimális napi költség: {T} \n Szükséges alapanyagok: \n")
  for i in range(len(alapanyagok)):
    if x[i].X > 0:
      out.write(f"{alapanyagok[i]["nev"]} {x[i].X} g \n")
  out.write(f"Összesített tápanyagtartalom: \n")
  out.write(f"Kalória {sum(x[i].X*alapanyagok[i]["kcal"] for i in range(len(alapanyagok)))} kcal \n")
  out.write(f"Fehérje {sum(x[i].X*alapanyagok[i]["feherje_g"] for i in range(len(alapanyagok)))} g \n")
  out.write(f"Zsír {sum(x[i].X*alapanyagok[i]["zsir_g"] for i in range(len(alapanyagok)))} g \n")
  out.write(f"Szénhidtár {sum(x[i].X*alapanyagok[i]["szenhidrat_g"] for i in range(len(alapanyagok)))} g \n")
  out.write(f"Rost {sum(x[i].X*alapanyagok[i]["rost_g"] for i in range(len(alapanyagok)))} g \n")
  out.write(f"C Vitamin {sum(x[i].X*alapanyagok[i]["vitamin_c_mg"] for i in range(len(alapanyagok)))} mg \n")
  out.write(f"A Vitamin {sum(x[i].X*alapanyagok[i]["vitamin_a_ug"] for i in range(len(alapanyagok)))} µg \n")
  out.write(f"Kalcium {sum(x[i].X*alapanyagok[i]["kalcium_mg"] for i in range(len(alapanyagok)))} mg \n")

