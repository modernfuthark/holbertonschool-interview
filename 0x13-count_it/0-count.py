#!/usr/bin/python3
"""
0-count
"""

import requests
import re


def count_words(subreddit, word_list, total={}, aft=None):
    """ count occurences of words """

    if len(total) == 0:
        for word in word_list:
            total[word] = 0

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    if aft:
        url += "?after={}".format(aft)

    req = requests.get(url, allow_redirects=False,
                       headers={"User-Agent": "0x13-count_it_TimSninsky"})

    if req.status_code != 200:
        print(req.status_code)
        return

    data = req.json()['data']

    for post in data['children']:
        title = post['data']['title']
        for k,v in total.items():
            pattern = k + "(?!\w+)"
            result = re.findall(pattern, title, flags=re.IGNORECASE)
            total[k] += len(result)

    aft = data['after']
    if aft is not None:
        return count_words(subreddit, word_list, total, aft)
    else:
        sorted_totals = reversed(sorted(total.items(), key=lambda kv: kv[1]))
        for item in sorted_totals:
            if item[1] > 0:
                print("{}: {}".format(item[0], item[1]))
    return
