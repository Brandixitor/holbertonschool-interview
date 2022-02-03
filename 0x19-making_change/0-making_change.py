#!/usr/bin/python3
"""
makeChange method
"""


def makeChange(coins, total):
    """
    determine the fewest number of coins needed
    to meet a given amount total
    """
    number_coins = 0
    cents = 0
    if total <= 0:
        return 0

    coins = sorted(coins, reverse=True)

    for coin in coins:
        while cents + coin <= total:
            cents += coin
            number_coins += 1
        if cents == total:
            return number_coins
    return -1
