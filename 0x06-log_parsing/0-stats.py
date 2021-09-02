#!/usr/bin/python3
import sys
import collections
""" Script that reads stdin line by line and computes metrics. """

i = 0
size = 0
key = ""
metrics = collections.OrderedDict({})
possible_code = ['200', '301', '400', '401', '403', '404', '405', '500']


def print_stuff():
    """ Prints file isze + metrics """
    print("File size: {}".format(str(size)))
    for k in sorted(metrics):
        print("{}: {}".format(str(k), str(metrics[k])))


try:
    for line in sys.stdin:
        b = [str(x) for x in line.split(' ')]
        if len(b) > 2:
            key = b[-2]
            if (key in metrics.keys()):
                metrics[key] += 1
            else:
                if key in possible_code:
                    metrics[key] = 1
            size += int(b[-1])
        i += 1
        if (i == 10):
            print_stuff()
            i = 0
except KeyboardInterrupt:
    pass
finally:
    print_stuff()
