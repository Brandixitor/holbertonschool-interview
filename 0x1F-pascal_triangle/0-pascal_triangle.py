#!/usr/bin/python3
"""pascal triangle"""


def pascal_triangle(n):
    """Computes N rows of Pascal's Triangle"""
    pascal = [[1]]
    for _ in range(n - 1):
        pascal += [[1] + [pascal[-1][i] + pascal[-1][i + 1]
                   for i in range(len(pascal[-1]) - 1)] + [1]]
    return pascal if n > 0 else []
