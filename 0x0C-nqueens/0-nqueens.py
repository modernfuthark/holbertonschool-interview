#!/usr/bin/python3
""" Solve the N Queens problem. """


import sys


def printBoard(board, size):
    """ Prints the board """

    temp = []

    for c in range(size):
        for r in range(size):
            if board[r][c] == 1:
                temp.append([c, r])
    print(temp)


def confirmSpace(board, r, c):
    """ Checks if the space can hold a queen """

    for i in range(c, -1, -1):
        if board[r][i] == 1:
            return False

    tempC = c
    for i in range(r, -1, -1):
        if board[i][tempC] == 1:
            return False
        tempC -= 1

    tempC = c
    for i in range(r, len(board)):
        if board[i][tempC] == 1:
            return False
        tempC -= 1

    return True


def recursiveSolve(board, c):
    """ Recursively solve the problem, starting from col 0 """

    if c == len(board):
        printBoard(board, len(board))
        return

    for r in range(len(board)):
        if confirmSpace(board, r, c):
            board[r][c] = 1
            recursiveSolve(board, c + 1)
            board[r][c] = 0


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

try:
    n = int(sys.argv[1])
except:
    print("N must be a number")
    sys.exit(1)

if n < 4:
    print("N must be at least 4")
    sys.exit(1)

board = [[0 for c in range(n)] for r in range(n)]
recursiveSolve(board, 0)
