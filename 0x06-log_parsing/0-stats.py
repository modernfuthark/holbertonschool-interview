#!/usr/bin/python3
""" Reads stdin and gathers data, printing data every 10 reads """
import sys
import re


counter = 0
codes = {200: 0, 301: 0, 400: 0,
         401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
tester = '#.#.#.# - [#-#-# #:#:#.#] "GET /projects/# HTTP/#.#" # #'
gfilesize = 0  # Global file size

try:
    for L in sys.stdin:
        if re.sub('\d+', '#', L.rstrip('\n')) == tester:
            # print(counter + 1)  # +1 for readability
            scode = int(re.match('(?:.*?\d+){14}.*?(\d+)',
                        L.rstrip('\n')).group(1))
            fsize = int(re.findall('\d+$', L.rstrip('\n'))[0])

            if scode in codes:
                codes[scode] += 1
                gfilesize += fsize
            if counter < 10:
                counter += 1
            else:
                print("File size: {}".format(gfilesize))
                for k in codes:
                    if codes[k] != 0:
                        print("{}: {}".format(k, codes[k]))
                counter = 0
except KeyboardInterrupt:
    print("File size: {}".format(gfilesize))
    for k in codes:
        if codes[k] != 0:
            print("{}: {}".format(k, codes[k]))
