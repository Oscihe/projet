
"""
Created on Mon Nov  8 18:39:29 2021

@author: Oscar
"""
import json
import csv
list=[]
for k in range(0,182):
    for t in range(1,5):
        p=str(t)
        string="precipitation"+p+".json"
        with open(string) as f:
            data=json.load(f)
            x=data["data_1h"]["precipitation"][0]
            #y=data["data_1h"]["time"]
            list.append(x)
           # for l in range(len(x)):
               # list.append(x[l])
                #list.append(y[l])
            f.close()
    print(list)
        with open("precipitations"+p+".csv","w",newline="") as f:
            file_precipitation=csv.writer(f)
            file_precipitation.writerow(list)
            print(list)
            f.close()
    #Creation d'une liste avec les temps et precipitation considérées, 
    #par heure.
             
