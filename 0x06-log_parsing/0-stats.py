#!/usr/bin/python3
import sys
import re
import signal


def Main():
    """ Main function """

    # Signal catching
    def sig(sNum, sFrame):
        print("File size: {}".format(gfilesize))
        for k in codes:
            if codes[k] != 0:
                print("{}: {}".format(k, codes[k]))
    signal.signal(signal.SIGINT, sig)

    # Start parsing function...
    counter = 0
    codes = {200: 0, 301: 0, 400: 0,
               401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
    tester = '#.#.#.# - [#-#-# #:#:#.#] "GET /projects/# HTTP/#.#" # #'
    gfilesize = 0  # Global file size

    for L in sys.stdin:
        if re.sub('\d+', '#', L.rstrip('\n')) == tester:
            #print(counter + 1)  # +1 for readability

            scode = int(re.match('(?:.*?\d+){14}.*?(\d+)', L.rstrip('\n')).group(1))
            fsize = int(re.findall('\d+$', L.rstrip('\n'))[0])  # Really doesn't like using .match

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

if __name__ == "__main__":
        Main()
