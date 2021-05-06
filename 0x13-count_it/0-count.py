#!/usr/bin/python3
"""
0-count
"""

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
        print("")
        return None

    data = req.json()['data']

    for post in data['children']:
        title = post['data']['title']
        for k, v in total.items():
            # Split the lowercase title and count finds of the key
            splitTitle = title.lower().split()
            total[k] += splitTitle.count(k.lower())

    # Check if there's an after, and recurse if so
    aft = data['after']
    if aft is not None:
        return count_words(subreddit, word_list, total, aft)
    else:
        # Combine duplicates into a lowercase key
        sortedTotals = {}
        for k, v in total.items():
            if v > 0:
                low = k.lower()
                if low not in sortedTotals:
                    sortedTotals[low] = v
                else:
                    sortedTotals[low] += v
        if len(sortedTotals) == 0:
            print("")
            return None

        # Sort dictionary by value
        sortedTotals = sorted(sortedTotals.items(),
                              key=lambda kv: kv[1], reverse=True)

        # Print list
        for k, v in sortedTotals:
                print("{}: {}".format(k, v))
        return sortedTotals
