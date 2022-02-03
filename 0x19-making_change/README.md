# 0x19. Making Change

## Requirements
### General
* Allowed editors: vi, vim, emacs
* All your files will be interpreted/compiled on Ubuntu 14.04 LTS using python3 (version 3.4.3)
* All your files should end with a new line
* The first line of all your files should be exactly #!/usr/bin/python3
* A README.md file, at the root of the folder of the project, is mandatory
* Your code should use the PEP 8 style (version 1.7.x)
* All your files must be executable

## Tasks
0. [Change comes from within](https://github.com/JennyHadir/holbertonschool-interview/blob/main/0x19-making_change/0-making_change.py)

Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount total.

* Prototype: def makeChange(coins, total)
* Return: fewest number of coins needed to meet total
* If total is 0 or less, return 0
* If total cannot be met by any number of coins you have, return -1
* coins is a list of the values of the coins in your possession
* The value of a coin will always be an integer greater than 0
* You can assume you have an infinite number of each denomination of coin in the list
* Your solution’s runtime will be evaluated in this task