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

                # Left
                if j > 0:
                    if grid[i][j - 1] == 0:
                        perim += 1
                else:
                    perim += 1

                # Right
                if j + 1 < len(grid[i]):
                    if grid[i][j + 1] == 0:
                        perim += 1
                else:
                    perim += 1

                # Up
                if i < len(grid) - 1:
                    if grid[i - 1][j] == 0:
                        perim += 1
                else:
                    perim += 1

                # Down
                if i + 1 < len(grid):
                    if grid[i + 1][j] == 0:
                        perim += 1
                else:
                    perim += 1
    return perim
