#!/usr/bin/python3
"""
Calculate how much water will be retained after it rains.
Wall width is 1
"""


def rain(walls):
    rainAmount = 0
    rainFill = 0
    wallsLength = len(walls)
    if (wallsLength == 0):
        return (0)

    for i in range(1, wallsLength - 1):
        leftPeak = walls[i]
        rightPeak = walls[i]
        for L in range(0, i):
            if (walls[L] > leftPeak):
                leftPeak = walls[L]
        for R in range(i + 1, wallsLength):
            if (walls[R] > rightPeak):
                rightPeak = walls[R]
        rainFill = min(leftPeak, rightPeak) - walls[i]
        rainAmount += rainFill

    return (rainAmount)
