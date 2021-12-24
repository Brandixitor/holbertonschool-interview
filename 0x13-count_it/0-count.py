#!/usr/bin/python3
"""
    Parses the title of all hot articles, and prints a sorted
    count of given keywords (case-insensitive, delimited by spaces.
"""
import json
import re
import requests
import time


def count_elements(request, word_list, results):
    """ Counts number of elements """
    for title in request['data']['children']:
        datas = title['data']['title'].split(" ")
        for i in range(len(datas)):
            datas[i] = datas[i].lower()
            if (datas[i] in word_list):
                if (datas[i] in results.keys()):
                    results[datas[i]] += word_list.count(datas[i])
                else:
                    results[datas[i]] = word_list.count(datas[i])
    return results


def count_words(subreddit, word_list, results={}, param={'limit': 100}):
    """ Main function to count and print the words """
    baseLink = 'https://api.reddit.com/r/%s/hot.json' % subreddit

    if ('after' not in param):
        word_list = [str.lower() for str in word_list]

    link = baseLink
    customHeaders = {'User-agent': 'HolbertonSchoolTask'}
    r = requests.get(link, headers=customHeaders,
                     params=param, allow_redirects=False)

    if (r.status_code != 200):
        return
    data = r.content

    data = json.loads(data.decode('utf-8'))
    param = {'limit': 100, 'count': 100, 'after': data['data'].get('after')}
    if (data['data'].get('after') is None):
        results = count_elements(data, word_list, results)
        results = sorted(
            results.items(), key=lambda x: (-x[1], x[0]), reverse=False
            )
        for i in results:
            print("{}: {}".format(i[0], i[1]))
    else:
        results = count_elements(data, word_list, results)
        count_words(subreddit, word_list, results, param)
