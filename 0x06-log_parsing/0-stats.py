#!/usr/bin/python3
""" Reads stdin and gathers data, printing data every 10 reads """
import sys
import re


def printStats():
    """ Prints current logged statistics """
    print("File size: {}".format(totalSize))

    for k in sorted(codes.keys()):
        if codes[k] != 0:
            print("{}: {}".format(k, codes[k]))

counter = 0  # Loop counter
totalSize = 0
codes = {'200': 0, '301': 0, '400': 0,
         '401': 0, '403': 0, '404': 0, '405': 0, '500': 0}

try:
    for L in sys.stdin:
        if len(re.findall('\s', L.rstrip('\n'))) == 8:
            scode = re.findall('\w+', L.rstrip('\n'))[-2]
            fsize = re.findall('\d+$', L.rstrip('\n'))[0]
            totalSize += int(fsize)

            if scode in codes:
                codes[scode] += 1

            counter += 1
            if counter > 9:
                printStats()
                counter = 0

    printStats()

except KeyboardInterrupt:
    printStats()
    raise
