# -*- coding: utf-8 -*-
"""
Created on Fri Nov  5 22:04:45 2021

@author: Oscar
"""

import json
for t in range(1,5):
    p=str(t)
    string="precipitation"+p+".json"
    with open(string) as f:
        data=json.load(f)
    for precipitation in data["history_day"]:
        print(precipitation)