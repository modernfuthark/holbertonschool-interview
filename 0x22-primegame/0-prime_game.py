#!/usr/bin/python3

def primeCheck(n):
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

def remover(L, n):
    for i in L:
        if i % n == 0:
            L.remove(i)

def isWinner(x, nums):
    if x <= 0 or nums is None or x != len(nums):
        return None

    ben = 0
    maria = 0
    for round in range(x):
        new = [n for n in range(1, nums[round] + 1)]
        turn = 0
        while len(new) > 1:
            for i in new:
                if primeCheck(i):
                    new.remove(i)
                    remover(new, i)
                    if turn % 2 == 0:
                        ben += 1
                    else:
                        maria += 1
            turn += 1

    return 'Maria' if maria > ben else 'Ben'
