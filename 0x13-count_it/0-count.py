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
        # Combine duplicates into a lowercase key
        sorted_totals = {}
        for k, v in total.items():
            if v > 0:
                low = k.lower()
                if low not in sorted_totals:
                    sorted_totals[low] = v
                else:
                    sorted_totals[low] += v
        if len(sorted_totals) == 0:
            print()
            return sorted_totals

        # Sort dictionary by value
        sorted_totals = sorted(sorted_totals.items(),
                               key=lambda kv: kv[1], reverse=True)

        # Print list
        for k, v in sorted_totals:
                print("{}: {}".format(k, v))
    return
