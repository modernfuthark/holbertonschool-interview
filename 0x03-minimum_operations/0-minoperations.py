#!/usr/bin/python3

"""
Calculates the minimum amount of operations to reach a number
"""


def minOperations(n):
    """
    Gets the minimum amount of operations to reach n.
    Only copying the value and pasting it is allowed.
    """

    ops = 0  # Operations
    hold = 1  # Clipboard
    goal = 1  # Goal number (wants to reach n)

    # Loop until goal is greater or equal to n
    while goal < n:
        if n % goal == 0:  # If goal can divide n equally, copy goal
            hold = goal
            ops += 1  # Copying counts as an operation
        goal += hold  # "Paste" clipboard onto goal
        ops += 1

    return ops
