#! /usr/bin/python3

import sys
import random

target_value = random.randint(0,10)

while True:
    try:
        value = int(input("Please enter a number:"))
    except ValueError:
        print("Invalid input:Please enter again")
        continue

    if value == target_value:
        print("You hit")
        break
    elif value < target_value:
        print("Too low")
    else :
        print("Too high")

print("Game over")
