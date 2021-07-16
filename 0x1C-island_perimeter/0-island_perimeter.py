#!/usr/bin/python3
"""
Island perimeter project
"""


def island_perimeter(grid):
    """ Island perimeter function """
    perim = 0

    for i in range(0, len(grid)):
        for j in range(0, len(grid[0])):
            # print(f"checking [{i}][{j}]")
            if grid[i][j] == 1:
                # Land found
                perim += 4
                # Left
                if j > 0:
                    if grid[i][j - 1] == 1:
                        perim -= 1

                # Right
                if j < len(grid[i]) - 1:
                    if grid[i][j + 1] == 1:
                        perim -= 1

                # Up
                if i > 0:
                    if grid[i - 1][j] == 1:
                        perim -= 1

                # Down
                if i < len(grid) - 1:
                    if grid[i + 1][j] == 1:
                        perim -= 1
    return perim
