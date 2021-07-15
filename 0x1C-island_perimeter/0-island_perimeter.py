#!/usr/bin/python3
"""
Island perimeter project
"""


def island_perimeter(grid):
    perim = 0

    for i in range(0, len(grid)):
        for j in range(0, len(grid[i])):
            # print(f"checking [{i}][{j}]")
            if grid[i][j] == 1:
                # land found
                if grid[i][j - 1] == 0:
                    perim += 1
                if grid[i][j + 1] == 0:
                    perim += 1
                if grid[i - 1][j] == 0:
                    perim += 1
                if grid[i + 1][j] == 0:
                    perim += 1
    return perim


if __name__ == "__main__":
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    print(island_perimeter(grid))
