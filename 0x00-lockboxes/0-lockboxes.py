#!/usr/bin/python3
""" Lockboxes file """


def canUnlockAll(boxes):
    """ Checks if there are the required keys in the given boxes """
    if boxes:
        keys = [0]  # Box 0 is unlocked
        # Gets the length of array boxes as an array
        required = [i[0] for i in enumerate(boxes)]

        for i in range(0, len(boxes)):
            for v in boxes[i]:
                if v not in keys and v < len(boxes) and v != i:
                    keys.append(v)
                    i = v

        # print(f'Required: {required}\nHas: {sorted(keys)}')

        return sorted(keys) == required
    return False
