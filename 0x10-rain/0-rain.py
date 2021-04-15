#!/usr/bin/python3
"""
0-rain
"""


def rain(walls):
    """ rain function """
    if type(walls) is not list or len(walls) <= 1:
        return 0

    size = len(walls)
    totalWater = 0
    lastWall = 0
    currentPool = 0

    for i in range(size):
        # Bigger wall found, set lastWall to it
        if walls[i] >= walls[lastWall]:
            lastWall = i
            currentPool = 0
        else:
            # Add "size" of pit between lastWall and current index
            totalWater += walls[lastWall] - walls[i]
            currentPool += walls[lastWall] - walls[i]

    if lastWall < size - 1:
        # Backtrack through list, since last wall wasn't at the end of the list
        # Remove last pool for recalculation
        if walls[i] < walls[lastWall]:
            totalWater -= currentPool
        lastWallcp = lastWall
        lastWall = size - 1
        # Iterate backwards from end of list to lastWall
        for i in range(size - 1, lastWallcp, -1):
            # Check if the current wall is greater than lastWall
            if walls[i] >= walls[lastWall]:
                lastWall = i
            else:
                # Add "size" of pit between lastWall and current index
                totalWater += walls[lastWall] - walls[i]

    return totalWater
