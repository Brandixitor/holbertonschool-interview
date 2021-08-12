#!/usr/bin/python3
""" Calculates the fewest number of operations needed to result in exactly n H characters. """
def minOperations(n):
    """ Calculates the fewest number of operations needed to result in exactly n H characters. """
    copy = "H"
    output = ""
    i = 0
    if (n < 2):
        return 0
    while (len(output) < n):
        if (i % 2 == 0):
            output += copy
        else:
            copy = output
            output += copy
        i += 1
    if (i == n):
        return i
    return i + 1
