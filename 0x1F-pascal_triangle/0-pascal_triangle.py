#!/usr/bin/python3
"""
0-pascal_triangle - Create a Pascal Triangle
"""


def pascal_triangle(n):
    """Create a pascal triangle"""
    if n <= 0:
        return []

    result = []

    for row in range(0, n):
        inner = [1 for _ in range(row + 1)]
        result.append(inner)
        if row > 1:
            for col in range(1, len(inner) - 1):
                result[row][col] =\
                    (result[row - 1][col - 1]) + (result[row - 1][col])

    return result
