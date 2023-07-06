import sys
import random
import csv
from cs50 import SQL

def main1():
    if len(argv) == 2:
        print(f"Hello, {argv[1].title()}")
    else :
        print("Hello dude")

def main2():
    return (random.random() > 0 and random.random() < 1)

def main3():
    with open("dna/sequences/20.txt", 'r') as file:
        reader = file.read()
        print(len(reader))

def main4():
    with open("dna/databases/large.csv") as file:
        reader = csv.DictReader(file) # It's accessible outside with
        headers = reader.fieldnames
        L = []
        print(headers[1:])
        for row in reader :
            L.append(row["name"])

        sys.exit(L)
        print(455555555)

def main5():

    while True :
        a = int(input("Enter a nbr : "))
        if a == 5:
            print("Goof")
        else :
            break

def main6():
    with open("Notes.csv") as file:
        reader = csv.DictReader(file)
        titles = reader.fieldnames
        print(titles)

        for row in reader:
            math_note = int(row["math"])
            if math_note == 100:
                print(row)
                print()


main6()