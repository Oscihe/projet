import numpy as np
#le document contient toutes les altitudes en Suisse, dans des carrés de 200x200 m
altitudes = np.genfromtxt('DHM200.xyz', delimiter = ' ', dtype = None)

#Prendre que les données qui sont dans notre zones autour de la Grande Dixence:
#la zone rectangulaire (autour du Lac des Dix) que l'on considère est entre ces coordonnées :
#limite Nord-Ouest : 2'600'002.7, 1'095'486.2
#Limite Nord-Est : 2'600'002.7, 1'095'298.2
#Limite Sud-Est : 2'593'045.2, 1'095'298.2
#Limite Sud-Ouest : 2'593'045.2, 1'095'486.2

coordx_tout = dhm200[:, 0]
coordy_tout = dhm200[:, 1]
alt_tout = dhm200[:, 2]

indices_x = []
indices_y = []
for i in range(0, len(coordx_tout)):
    if 593045.2 <= coordx_tout[i] <= 600002.7:
        indices_x.append(i)

for i in range(0, len(coordy_tout)):
    if 095298.2 <= coordy_tout[i] <= 095486.2:
        indices_y.append(i)

print(f"{indices_x}")
