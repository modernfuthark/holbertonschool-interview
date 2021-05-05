#!/usr/bin/python3
"""
0-count
"""

import re
import requests


def count_words(subreddit, word_list, total={}, aft=None):
    """ count occurences of words """

    # On the first call of the function,
    # create dictionary of words with a count of 0
    if len(total) == 0:
        for word in word_list:
            total[word] = 0

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    if aft:
        url += "?after={}".format(aft)

    req = requests.get(url, allow_redirects=False,
                       headers={"User-Agent": "0x13-count_it_TimSninsky"})

    if req.status_code != 200:
        print()
        return

    data = req.json()['data']

    for post in data['children']:
        title = post['data']['title']
        for k, v in total.items():
            # Create pattern with key and a negative lookahead
            pattern = k + "(?!(\w+)|(\S+))"
            # Get all instances of pattern in title, and add to dictionary
            result = re.findall(pattern, title, flags=re.IGNORECASE)
            total[k] += len(result)

    # Check if there's an after, and recurse if so
    aft = data['after']
    if aft is not None:
        return count_words(subreddit, word_list, total, aft)
    else:
        # Sort dictionary by the key's values
        sorted_totals = resolveDupes(total)
        for item in sorted_totals:
            if item[1] > 0:
                print("{}: {}".format(item[0], item[1]))
    return


def resolveDupes(list):
    """ turns dictionary into a sorted dictionary with no duplicates """
    newDict = {}

    for k, v in list.items():
        low = k.lower()
        if low not in newDict:
            newDict[low] = list[k]
        else:
            newDict[low] += list[k]
    return reversed(sorted(newDict.items(), key=lambda kv: kv[1]))
