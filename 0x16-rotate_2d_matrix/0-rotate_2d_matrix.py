#!/usr/bin/python3
"""
0-rotate_2d_matrix - Rotates a 2D matrix 90 degrees clockwise
"""


def rotate_2d_matrix(matrix):
    """ Main function """
    # Clone and reverse matrix
    tempMatrix = [i[:] for i in matrix]
    tempMatrix.reverse()

    # Loop through matrix
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            # Rotate 90 deg
            # matrix[i][j] = reversed matrix[j][i]
            matrix[i][j] = tempMatrix[j][i]
