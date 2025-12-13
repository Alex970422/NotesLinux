#!/usr/bin/env python3

chiffres = input("write a num made of 1 to 20 digit")
f = open("Fichier", "x")
f.close()
with open("Fichier", "w" ) as f:
    for char in chiffres:
        f.write(char + "\n")
f.close()
with open("Fichier","r") as f:
    for x in f:
        print(x)
f.close()

