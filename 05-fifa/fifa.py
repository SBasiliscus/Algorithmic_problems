import csv
import gurobipy as gp
from gurobipy import GRB

matrix = [[[0 for _ in range(3)]for _ in range(3)]for _ in range(3)] #plusz egy dimenzió amiben elősször csak összeszámolom a gólokat ([][][1]) összeszámolóm az összes rúgást [][][2] majd kiszámolom az empírikus valószínűséget [][][0]

with open("fifa.csv", newline="", encoding="utf-8") as f:
  reader = csv.DictReader(f)
  for row in reader:
    rw =  0 if row["kapus_zona"] == "bal" else ( 1 if row["kapus_zona"] == "kozep" else 2)    
    clm =  0 if row["rugo_zona"] == "bal" else ( 1 if row["rugo_zona"] == "kozep" else 2)
    matrix[rw][clm][2] += 1
    if row["gol"] == "1":
        matrix[rw][clm][1] += 1

for i in range(3):
   for j in range(3):
        if matrix[i][j][2] > 0:
            matrix[i][j][0] = matrix[i][j][1] / matrix[i][j][2]
        else:
            matrix[i][j][0] = 1/2

m = gp.Model(f"fifa")
alpha = m.addVar(lb=0,ub=1, vtype=GRB.CONTINUOUS, name= "alpha")
x1 = m.addVar(lb=0,ub=1, vtype=GRB.CONTINUOUS, name= "x1")
x2 = m.addVar(lb=0,ub=1, vtype=GRB.CONTINUOUS, name= "x2")
x3 = m.addVar(lb=0,ub=1, vtype=GRB.CONTINUOUS, name= "x3")
m.addConstr(x1+x2+x3 <= 1)
m.addConstr(x1+x2+x3 >= 1)
m.addConstr(matrix[0][0][0]*x1 + matrix[0][1][0]*x2 + matrix[0][2][0]*x3 >= alpha)
m.addConstr(matrix[1][0][0]*x1 + matrix[1][1][0]*x2 + matrix[1][2][0]*x3 >= alpha)
m.addConstr(matrix[2][0][0]*x1 + matrix[2][1][0]*x2 + matrix[2][2][0]*x3 >= alpha)
m.setObjective(alpha, GRB.MAXIMIZE)
m.optimize()
beta = m.addVar(lb=0,ub=1, vtype=GRB.CONTINUOUS, name= "beta")
y1 = m.addVar(lb=0,ub=1, vtype=GRB.CONTINUOUS, name= "y1")
y2 = m.addVar(lb=0,ub=1, vtype=GRB.CONTINUOUS, name= "y2")
y3 = m.addVar(lb=0,ub=1, vtype=GRB.CONTINUOUS, name= "y3")
m.addConstr(y1+y2+y3 <= 1)
m.addConstr(y1+y2+y3 >= 1)
m.addConstr(matrix[0][0][0]*y1 + matrix[1][0][0]*y2 + matrix[2][0][0]*y3 <= beta)
m.addConstr(matrix[0][1][0]*y1 + matrix[1][1][0]*y2 + matrix[2][1][0]*y3 <= beta)
m.addConstr(matrix[0][2][0]*y1 + matrix[1][2][0]*y2 + matrix[2][2][0]*y3 <= beta)
m.setObjective(beta, GRB.MINIMIZE)
m.optimize()

with open("kimenet.txt", "w", encoding="utf-8") as out:
  out.write(f"Kifizetési mátrix (sorok: rúgó zóna, oszlopok: kapus zóna):\n             bal          kozep       jobb\nbal     ")  
  for i in range(3):    
      ##out.write(f"       {matrix[i][0][1]} / {matrix[i][0][2]}")
      out.write(f"       {matrix[i][0][0]}")
  out.write(f"\nkozep   ")  
  for i in range(3):    
      ##out.write(f"       {matrix[i][1][1]} / {matrix[i][1][2]}")  
      out.write(f"       {matrix[i][1][0]}")
  out.write(f"\njobb    ")  
  for i in range(3):    
      ##out.write(f"       {matrix[i][2][1]} / {matrix[i][2][2]}") 
      out.write(f"       {matrix[i][2][0]}")
    
  out.write(f"\nRúgó minimax stratégiája: \n - P(bal)={x1.X} \n- P(kozep)={x2.X}  \n- P(jobb)={x3.X} \nBiztonsági szint (gól valószínűség alsó korlát): {alpha.X}")

  out.write(f"\nKapus minimax stratégiája:\n- P(bal)={y1.X}\n- P(kozep)={y2.X}\n- P(jobb)={y3.X}\nBiztonsági szint (gól valószínűség felső korlát): {beta.X}")