#!/usr/bin/python3
"""
Plays the Prime Game
"""


def primeCheck(n):
    """ Checks if n is a prime number """
    if n <= 3:
        return n > 1
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i ** 2 <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True


def containsPrime(L):
    """ Checks if L contains any prime numbers """
    for i in L:
        if primeCheck(i):
            return True


def remover(L, n):
    """ Removes multiples of n from list L """
    for i in L:
        if i % n == 0:
            L.remove(i)


def isWinner(x, nums):
    """ Prime Game """
    if x <= 0 or nums is None or x != len(nums):
        return None

    ben = 0
    maria = 0
    for round in range(x):
        new = [n for n in range(1, nums[round] + 1)]
        turn = 0
        while containsPrime(new):
            turn += 1
            for i in new:
                if primeCheck(i):
                    new.remove(i)
                    remover(new, i)
                    break

        if turn % 2 == 0:
            ben += 1
        else:
            maria += 1

    return 'Maria' if maria > ben else 'Ben'
