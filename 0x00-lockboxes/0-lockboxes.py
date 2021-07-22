#!/usr/bin/python3


def canUnlockAll(boxes):
    """ Function that unlocks all boxes """

    checked = [False for v in range(len(boxes))]
    checked[0] = True
    stack = boxes[0]

        while(len(stack)):
            element = stack[-1]
            stack.pop()
        try:
            if not visited[element]:
                checked[element] = True
            for node in boxes[element]:
                if not checked[node]:
                    stack.append(node)
        except:
            pass
    return all(checked)