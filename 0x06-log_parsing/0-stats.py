#!/usr/bin/python3
""" Reads stdin and gathers data, printing data every 10 reads """
import sys
import re


def printStats(size, tracker):
    """ Prints current logged statistics """
    print("File size: {}".format(size))

    sortedCodes = sorted(tracker.keys())
    for k in sortedCodes:
        if codes[k] != 0:
            print("{}: {}".format(k, codes[k]))

counter = 0  # Loop counter
totalSize = 0
codes = {200: 0, 301: 0, 400: 0,
         401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
# Tester is the expected input, but with all numbers replaced
tester = '#.#.#.# - [#-#-# #:#:#.#] "GET /projects/# HTTP/#.#" # #'

try:
    for L in sys.stdin:
        if re.sub('\d+', '#', L.rstrip('\n')) == tester:
            # print(counter + 1)  # +1 for readability
            scode = int(re.match('(?:.*?\d+){14}.*?(\d+)',
                        L.rstrip('\n')).group(1))
            fsize = int(re.findall('\d+$', L.rstrip('\n'))[0])
            totalSize += fsize

            if scode in codes:
                codes[scode] += 1

            if counter < 9:
                counter += 1
            else:
                printStats(totalSize, codes)
                counter = 0
    printStats(totalSize, codes)

except KeyboardInterrupt:
    printStats(totalSize, codes)
