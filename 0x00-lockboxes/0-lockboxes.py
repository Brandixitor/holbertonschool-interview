#!/usr/bin/python3
""" Module that containes "canUnlockAll" function"""


def canUnlockAll(boxes):
    """ function
    Args:
        boxes: list of lists of integers
    return: boolean: true or false
    """

    listOfKeys = [0]
    for key in listOfKeys:
        for k in boxes[key]:
            if k not in listOfKeys and k < len(boxes):
                listOfKeys.append(k)
    for i in range(len(boxes)):
        if i not in listOfKeys:
            return False
    return True
