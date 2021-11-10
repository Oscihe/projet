import numpy as np
#le document contient toutes les altitudes en Suisse, dans des carrés de 200x200 m
print("Lecture du document")
dhm200 = np.genfromtxt('DHM200.xyz', delimiter = ' ', dtype = None)

#Prendre que les données qui sont dans notre zones autour de la Grande Dixence:
#la zone rectangulaire (autour du Lac des Dix) que l'on considère est entre ces coordonnées :
#limite Nord-Ouest : 2'600'002.7, 1'095'486.2
#Limite Nord-Est : 2'600'002.7, 1'095'298.2
#Limite Sud-Est : 2'593'045.2, 1'095'298.2
#Limite Sud-Ouest : 2'593'045.2, 1'095'486.2

x_tout = dhm200[:, 0]
y_tout = dhm200[:, 1]
alt_tout = dhm200[:, 2]

x_list = []
y_list = []
for i in range(0, len(x_tout)):
    if 593045.2 <= x_tout[i] <= 600002.7:
        x_list.append(i)

for i in range(0, len(y_tout)):
    if 593045.2 <= y_tout[i] <= 600002.7:
        xylist.append(i)

x = np.array(x_list)
y = np.array(y_list)

#comme dans l'exercice Suisse :
xmin = np.min(x)
ymin = np.min(y)

index_x = (x-xmin)/200
index_y = (y-ymin)/200



taille_x = int(np.max(index_x))+1
taille_y = int(np.max(index_y))+1

print(f"{index_x}")

"""
altitudes = np.zeros((taille_y, taille_x))

altitudes[(index_y.astype('int32')), (index_x.astype('int32'))] = alt
"""


"""
indices_x = []
indices_y = []
for i in range(0, len(coordx_tout)):
    if 593045.2 <= coordx_tout[i] <= 600002.7:
        indices_x.append(i)

for i in range(0, len(coordy_tout)):
    if 095298.2 <= coordy_tout[i] <= 095486.2:
        indices_y.append(i)

indice_xmin = np.min(indices_x)
indice_ymin = np.min(indices_y)

#On initialise les indices du tableau initial pour avoir les indices du tableau de notre zone:
x_tabl = []
y_tabl = []
for i in range(0, len(indices_x)):
    x_tabl.append((indices_x[i]-indice_xmin))
for i in range(0, len(indices_y)):
    y_tabl.append((indices_y[i]-indice_ymin))


#print(f"{indices_x}\n\n")
#x_tabl_tri = x_tabl.sort()
print(f"{coordx_tout}")
"""
